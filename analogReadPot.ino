const int potPin=34;
double val=0;
void setup() {
 Serial.begin(115200);
 

}

void loop() {
  val=analogRead(potPin);
  val=(val/4095)*3.3;
  Serial.print(val);
  Serial.println("volt");
  delay(300);

}
