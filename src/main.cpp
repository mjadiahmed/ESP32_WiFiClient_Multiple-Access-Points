/**
 * @file main.cpp
 * @author Ahmed MJADI (mjadiahmed@gmail.com)
 * @brief Connect your ESP32 to the Accesspoint with the best signal
 * @version 0.1
 * @date 2022-10-13
 * @copyright Copyright (c) 2022
 */

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiMulti.h>

WiFiMulti wifiMulti;

void setup()
{
  Serial.begin(9600);
  delay(10);

  wifiMulti.addAP("NEXT-AP1", "2899100*-+");
  wifiMulti.addAP("NEXT-AP1", "Next2022");
  wifiMulti.addAP("NEXTRONIC-1", "Next2021");

  Serial.println("Connecting Wifi...");

  if (wifiMulti.run() == WL_CONNECTED)
  {
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  }
}

void loop()
{
  if (wifiMulti.run() != WL_CONNECTED)
  {
    Serial.println("WiFi not connected!");
    delay(1000);
  }
  // Serial.println(WiFi.localIP());

  Serial.print("WiFi SSID: ");
  Serial.print(WiFi.SSID());
  Serial.print("   ||   AP_MAC: ");
  Serial.print(WiFi.BSSIDstr());
  Serial.print("  ||   RSSI: ");
  Serial.print(WiFi.RSSI());
  Serial.print("  ||   Channel: ");
  Serial.println(WiFi.channel());

  delay(1000);
}
