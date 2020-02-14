#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>



int leds[3] = {D0, D1, D2};
int states[3] = {LOW, LOW, LOW};
int totalDevices = 3;


#define firebaseURl "tdcreations-5ac55.firebaseio.com"
#define authCode "81uyMLz8Yes8o0Wv2BiphVBbPTZWMO2P06Gldm32"

#define wifiName "TD"
#define wifiPass "tdC141csc801"


String chipId = "123";


void setupFirebase() {

  Firebase.begin(firebaseURl, authCode);
}

void setupWifi() {

  WiFi.begin(wifiName, wifiPass);

  Serial.println("Hey i 'm connecting...");

  while (WiFi.status() != WL_CONNECTED) {

    Serial.println(".");
    delay(500);
  }

  Serial.println();
  Serial.println("I 'm connected and my IP address: ");
  Serial.println(WiFi.localIP());
}


void setup() {

  Serial.begin(9600);

  setupWifi();
  setupFirebase();

  /*setupPinsMode(); */

}



void getData()  {

  String path = chipId + "/states";
  FirebaseObject object = Firebase.get(path);

  bool led1 = object.getBool("001");
  bool led2 = object.getBool("002");
  bool led3 = object.getBool("003");

  Serial.println("Led 1: ");
  Serial.println(led1);

  //
  Serial.println();
  Serial.println("Led 2: ");
  Serial.println(led2);

  //
  Serial.println();
  Serial.println("Led 3: ");
  Serial.println(led3);


// write output high or low to turn on or off led
/*  digitalWrite(leds[0], led1);

  digitalWrite(leds[1], led2);
  
  digitalWrite(leds[2], led3);*/

}
void loop() {


  getData();


}

void setupPinsMode() {

  // setup Pin mode as output.


 /* for (int i; i < totalDevices; i++) {

    Serial.printf("Setup Output for pin %d", leds[i]);
    pinMode(leds[i], OUTPUT);
  }*/
}

