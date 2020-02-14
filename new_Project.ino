#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST ""
#define FIREBASE_AUTH ""
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

void setup() {
  Serial.begin(115200);
  pinMode(13, OUTPUT);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  if(WiFi.status() == WL_CONNECTED){
           
      Serial.println("ok");
    }
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);


  
}

void loop() {
  String path   = "/";
  FirebaseObject object = Firebase.get(path);
  
  String cam = object.getString("cam");
  String fan = object.getString("fan");
  String light = object.getString("light");
  String pro = object.getString("pro");
  
  if(WiFi.status() == WL_CONNECTED){

    // cam
    if(cam == "true" ){
        Serial.println("Cam is on");
         digitalWrite(13, HIGH);  
        delay(1000);
      }else if(cam == "false"){
        Serial.println("Cam is off");
      }
    // fan
      if(fan == "true" ){
         Serial.println("Fan is on");
      }else if(fan == "false"){
        Serial.println("Fan is off");
      }
    //light
       if(light == "true" ){
         Serial.println("Light is on");
      }else if(light == "false"){
        Serial.println("Light is off");
      }
    //pro
       if(pro == "true" ){
         Serial.println("Pro is on");
      }else if(pro == "false"){
        Serial.println("Pro is off");
      }
  delay(1000);
  }
}
