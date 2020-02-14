#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST ""
#define FIREBASE_AUTH ""
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

void setup() {
  Serial.begin(9600);
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
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  
}

void loop() {

String path   = "/";
  FirebaseObject object = Firebase.get(path);

  String Email = object.getString("Email");
  String Light = object.getString("Light");
  String Name = object.getString("Name");
  String contact = object.getString("contact");

  if(WiFi.status() == WL_CONNECTED){

      Serial.println(Email);
      Serial.println(Light);
      Serial.println(Name);
      Serial.println(contact);     

      if(Light == "True"){
        digitalWrite(13, HIGH);   
      //                      
      } else {
        digitalWrite(13, LOW);   
       }
      delay(200);
    }
 
  
  
  
}
