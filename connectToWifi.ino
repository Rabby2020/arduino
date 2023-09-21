#include<WiFi.h>
void connectToWifi(){
  WiFi.mode(WIFI_STA);
  WiFi.begin("Zam Zam Tower","zam811976zam");
  Serial.print("Conneting to wifi");
  while(WiFi.status()!=WL_CONNECTED){
  Serial.print(".");
  delay(200);
  }
  Serial.println("\nConnected Successfully");
  Serial.print("Ip Address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Mac Address" );
  Serial.println(WiFi.macAddress());
}
void setup(){
  Serial.begin(115200);
  connectToWifi();
}
void loop(){

}