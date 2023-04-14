// Variablen
//EXT
// -button
const int pushbutton_1 = 3;  //neuer Sack
const int togglebutton_1 = 4;  // auto/manual
const int togglebutton_2 = 5;  // on off
// -leds
const int light_1 = 6; // Sackwechsel aktiv
const int light_2 = 8; // Hand aktiv
const int light_3 = 9; //  temperatur zu kalt
const int light_4 = 10; // temperatur richtig
const int light_5 = 11; // temperatur zu warm
const int light_6 = 12; // Auto aktiv (Regelung aktiv)
const int light_7 = 13; // System AN
// -poti
const int pot_1 = A1; // Regelverstärkung
const int pot_2 = A0; // dimming
// -traic
const int AC_LOAD = 7;    // Output to Opto Triac pin
//INT
// -temperatur
float a_sign = 0; //Digitaler Analgoeingangswert
float d_u = 0; //Spannungsabfall am Temperatursenser
float R_t = 0; //Wiederstandwert Temeratursensor
float temp = 0; //Temperatur
// -regler
float dimming = 50.00;
float a_sign_poti = 0; //Digitaler Analgoeingangswert
float y = 0; //Stellgröße
float w = 74; //Solltemperatur
float p = 4; //Regelverstärkung (P-Regler)


void setup() {
  // button
  pinMode(pushbutton_1, INPUT);
  pinMode(togglebutton_1, INPUT);
  pinMode(togglebutton_2, INPUT);
  // leds
  pinMode(light_1, OUTPUT);
  pinMode(light_2, OUTPUT);
  pinMode(light_3, OUTPUT);
  pinMode(light_4, OUTPUT);
  pinMode(light_5, OUTPUT);
  pinMode(light_6, OUTPUT);
  pinMode(light_7, OUTPUT);
  // triac
  pinMode(AC_LOAD, OUTPUT);// Set AC Load pin as output
  attachInterrupt(0, zero_crosss_int, RISING);  // Choose the zero cross interrupt # from the table above
  // debug messages
  Serial.begin(9600); //Start serial connection to computer
}

void zero_crosss_int()  // function to be fired at the zero crossing to dim the light
{
  // Every zerocrossing : (50Hz ^= 20ms  -->  (50 Hz, 1/2 Cycle ^= 10 ms = 10000us)
  // 10000 us delay until triac firing ^= dark
  // 0 us delay until triac firing ^= bright 
  
  int dimtime = ((dimming-100)*(-100));    
  delayMicroseconds(dimtime);    // Off cycle
  digitalWrite(AC_LOAD, HIGH);   // triac firing
  delayMicroseconds(10);         // triac On propogation delay (for 60Hz use 8.33)
  digitalWrite(AC_LOAD, LOW);    // triac Off
}

void loop() {
  
    //++++++++++++Temperatur +++++++++
    for(int i=0;i<5;i++){ // Mittelwert
      a_sign = a_sign+analogRead(A2);} // Mittelwert
    a_sign = a_sign/5;  // Mittelwert
    d_u=5.00*a_sign/1023.00;  // Spannungsabfall
    R_t=((d_u*660.00)/5.00)/(1.00-(d_u/5.00)); // Widerstandswer
    temp = (R_t-2490.08)/(-23.00);  // temperatur
    //temp = (analogRead(pot_2)/1024.00 * 100.0);  //test: delete as soon as tempearatur sensor is available
    
    // Temperatur traffic light
    if (temp > (w-1) && temp < (w+1)){
      digitalWrite(light_3, LOW);
      digitalWrite(light_4, HIGH);
      digitalWrite(light_5, LOW);}
    else if (temp > (w) && temp < (w+3)){
      digitalWrite(light_3, LOW);
      digitalWrite(light_4, HIGH);
      digitalWrite(light_5, HIGH);}
    else if((w+3) < temp){
      digitalWrite(light_3, LOW);
      digitalWrite(light_4, LOW);
      digitalWrite(light_5, HIGH);}
    else if(temp < (w-1) && temp > (w-3)){
      digitalWrite(light_3, HIGH);
      digitalWrite(light_4, HIGH);
      digitalWrite(light_5, LOW);}
    else if(temp < (w-3)){
      digitalWrite(light_3, HIGH);
      digitalWrite(light_4, LOW);
      digitalWrite(light_5, LOW);}
      
    // SYSTEM ON
    if (digitalRead(togglebutton_1) == 1){
      digitalWrite(light_7, HIGH);  //LED System on 
      
      // ++++++++++++ HAND ++++++++++++++++
      if (digitalRead(togglebutton_2) == 1){
        digitalWrite(light_2, HIGH);  // set LED on HAND activ
        digitalWrite(light_6, LOW);  // set LED OFF AUTO activ
        dimming = (analogRead(pot_2)/1024.00 * 100.0) + 1;  // "+1" couse no "0" allowed
        if (dimming > 99){  //higher than 99 is not allowed
          dimming = 99;}
      }
      
      // ++++++++++++ AUTO ++++++++++++++++
      else{
        digitalWrite(light_2, LOW);  // set LED OFF HAND activ
        digitalWrite(light_6, HIGH);  // set LED ON AUTO activ
        // Regler
          p = (analogRead(pot_1)/1024.0)*2;
        y = 33.00 + p *(temp-w); //w=SOLL temperatur, temp=ISTTemperatur, p=Reglerversärkung, 65=minimal drehzahl       
        if (y > 34.00){ 
          y = 35.00;}
        if (y < 30.00){
          y = 30.00;}
        dimming = y;

        // Sackwechsel
        if (digitalRead(pushbutton_1) == 1){
          digitalWrite(light_1, HIGH);
          dimming = 1;
          delay(400);
          digitalWrite(light_1, LOW);
        } 
      }  
    }

    // SYSTEM OFF
    else{
      Serial.println("OFF");
      dimming = 1;
      digitalWrite(light_2, LOW);
      digitalWrite(light_6, LOW);
      digitalWrite(light_7, LOW);
    }
    Serial.println(temp);
    Serial.println(dimming);
    delay(100); 
    

}
