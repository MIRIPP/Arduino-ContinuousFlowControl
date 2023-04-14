unsigned char AC_LOAD = 7;    // Output to Gate Triac pin
unsigned char dimming = 3;  // Dimming level (0-100)
const int pot_1 = A1;


void setup() {
  // put your setup code here, to run once:
  pinMode(AC_LOAD, OUTPUT);// Set AC Load pin as output
  attachInterrupt(0, zero_crosss_int, RISING);  // execute zero_crosss_int every phase change [phasen wechsel] (0 = PIN 2 on Arduino)

  Serial.begin(9600);

}

void zero_crosss_int()  // function to be fired at the zero crossing to dim the light
{
  // Every zerocrossing : (50Hz ^= 20ms  -->  (50 Hz, 1/2 Cycle ^= 10 ms = 10000us)
  // 10000 us delay until triac firing ^= dark
  // 0 us delay until triac firing ^= bright 
  
  int dimtime = ((dimming-100)*(-100));    // For 60Hz =>65    
  delayMicroseconds(dimtime);    // Off cycle
  digitalWrite(AC_LOAD, HIGH);   // triac firing
  delayMicroseconds(10);         // triac On propogation delay (for 60Hz use 8.33)
  digitalWrite(AC_LOAD, LOW);    // triac Off
}


void loop() {
  
  dimming = (analogRead(pot_1)/1024.00 * 100.0) + 1;  // "+1" couse no "0" allowed
  Serial.println(dimming);
  
  delay(50);
}
