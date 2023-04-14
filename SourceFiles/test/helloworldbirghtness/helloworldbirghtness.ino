void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    for (int brightness = 0; brightness<255; brightness++){
      analogWrite(12, brightness);
      delay(10);}
    for (int brightness = 255; brightness>0; brightness--){
      analogWrite(12vb   , brightness);
      delay(10);}
    digitalWrite(11,HIGH);
    delay(1000);
    digitalWrite(11,LOW);
    for (int brightness = 0; brightness<255; brightness++){
      analogWrite(10, brightness);
      delay(10);}
    for (int brightness = 255; brightness>0; brightness--){
      analogWrite(10, brightness);
      delay(10);}

}
  
