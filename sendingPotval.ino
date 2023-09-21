#include<WiFi.h>
#include<WiFiClient.h>
#include<HTTPClient.h>
String url;
String api="7U8LCMGWI5DBSFQ0";
String field="1";
int httpCode;
int pin=34;
double potValue;
WiFiClient wifi;
HTTPClient http;

void connectToWifi();
void sendGetReq(int data);
void setup() {
 Serial.begin(115200);
 connectToWifi();
}

void loop() {
  potValue=analogRead(pin);
  Serial.print(potValue/4096*3.3);
  Serial.println(" volt");
  sendGetReq(potValue);

}
// https://api.thingspeak.com/update?api_key=7U8LCMGWI5DBSFQ0&field1=0
void connectToWifi(){
  WiFi.mode(WIFI_STA);
  WiFi.begin("Rabby","password");
  Serial.print("Connecting to wifi");
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(1000);
  }
  Serial.println("\nConnected to wifi");
  Serial.print("Ip Address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Mac Addrese: ");
  Serial.println(WiFi.macAddress());
}
void sendGetReq(double data){
  url="http://api.thingspeak.com/update?api_key=";
  url+=api;
  url+="&field";
  url+=field;
  url+="=";
  url+=data;
  http.begin(wifi,url);
  Serial.println("Waiting for response");
  httpCode=http.GET();
  if(httpCode>0){
    Serial.print(data);
    Serial.println(" data sent successfully");
  }else{
    Serial.println("error in sending data");
  }
  http.end();
  delay(16000);

}