 /*
  Created by Igor Jarc
 See http://iot-playground.com for details
 Please use community forum on website do not contact author directly
 
 External libraries:
 - https://github.com/adamvr/arduino-base64
 
 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 version 2 as published by the Free Software Foundation.
 */
#include <ESP8266WiFi.h>
#include <Base64.h>

//AP definitions
#define AP_SSID "YOURWIFISSID"
#define AP_PASSWORD "YOUR SSID PASSWORD FOR ACCESS"
#define INPUT_PIN         5
#define USER_PWD_LEN      40
#define OUTPUT_PIN        12

int inputState;  
int oldInputState;
int digitalValue = 0;
int outputValue = 0;


void setup() {
  Serial.begin(115200);
  pinMode(INPUT_PIN, INPUT);
  pinMode(OUTPUT_PIN, OUTPUT);
  wifiConnect();
 

 }

void loop() {
  digitalValue = digitalRead(5); 
  //outputValue = digitalRead(12);  
  Serial.print(digitalValue);
  if(!digitalValue) {
  //outputState = "off";
  digitalWrite(OUTPUT_PIN, HIGH);
}
else {
  //outputState = "on";
  digitalWrite(OUTPUT_PIN, LOW);
}
  delay(300000);       //devide by 1000 for seconds. 5 mins here.
  //if(digitalValue > 0) {
    //digitalWrite(12, LOW);
  //}
  //else {
    //digitalWrite(12, LOW);
  //}
}
    


void wifiConnect()
{
    Serial.print("Connecting to AP");
    WiFi.begin(AP_SSID, AP_PASSWORD);
    //while (WiFi.status() != WL_CONNECTED) {
    //delay(1000);
   // Serial.print(".");
  //}
  
 // Serial.println("");
 // Serial.println("WiFi connected");
  delay(1000);  
  loop();
}


 

  
