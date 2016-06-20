#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager
#include <PubSubClient.h>

//for LED status
#include <Ticker.h>
#define BUTTON_WIFI 0


void setupWifi();
void setupWifiOnDemand();
void setupMqtt();
void loopMqtt();

void setup() {
  pinMode(BUTTON_WIFI, INPUT);
  pinMode(BUILTIN_LED, OUTPUT);

  // put your setup code here, to run once:
  Serial.begin(115200);
  setupWifi();
  setupMqtt();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(BUTTON_WIFI) == LOW) {
    setupWifiOnDemand();
  }
  loopMqtt();
  
  
}
