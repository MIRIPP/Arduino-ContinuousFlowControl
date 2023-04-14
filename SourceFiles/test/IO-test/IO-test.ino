const int pushbutton_1 = 3;
const int togglebutton_1 = 4;
const int togglebutton_2 = 5;

const int light_1 = 6;
const int light_2 = 8;
const int light_3 = 9;
const int light_4 = 10;
const int light_5 = 11;
const int light_6 = 12;
const int light_7 = 13;

const int pot_1 = A1;
const int pot_2 = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pushbutton_1, INPUT);
  pinMode(togglebutton_1, INPUT);
  pinMode(togglebutton_2, INPUT);

  pinMode(light_1, OUTPUT);
  pinMode(light_2, OUTPUT);
  pinMode(light_3, OUTPUT);
  pinMode(light_4, OUTPUT);
  pinMode(light_5, OUTPUT);
  pinMode(light_6, OUTPUT);
  pinMode(light_7, OUTPUT);
  
  Serial.begin(9600); //Start serial connection to computer

}

void loop() {
  // put your main code here, to run repeatedly:

  // light test
  if (digitalRead(pushbutton_1) == 1){
    digitalWrite(light_1, HIGH);
    digitalWrite(light_2, HIGH);
    digitalWrite(light_3, HIGH);
    digitalWrite(light_4, HIGH);
    digitalWrite(light_5, HIGH);
    digitalWrite(light_6, HIGH);
    digitalWrite(light_7, HIGH);
    Serial.println("ON");
  }
  else{
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    digitalWrite(light_3, LOW);
    digitalWrite(light_4, LOW);
    digitalWrite(light_5, LOW);
    digitalWrite(light_6, LOW);
    digitalWrite(light_7, LOW);
    Serial.println("OFF");    
  }

  // button test
  // Serial.println(digitalRead(pushbutton_1));
  // Serial.println(digitalRead(togglebutton_1));
  // Serial.println(digitalRead(togglebutton_2));
  
  // poti test
  // Serial.println(analogRead(pot_1));
  // Serial.println(analogRead(pot_2));
  delay(250);

  
}
