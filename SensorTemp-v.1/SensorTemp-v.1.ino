#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include "SensorTemp.h"

unsigned long previousMillis = 0;
const long interval = 2500;
SensorTemp mySensor;

void setup() {
  Serial.begin(115200);
  WiFiManager wifiManager;
  // Descomentar para resetear configuración
  wifiManager.resetSettings();
  wifiManager.autoConnect("ESP8266");
  Serial.println("Ya estás conectado");

  mySensor.begin();
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    mySensor.RunMain();
  }
}
