/**
 * @file main.cpp
 * @author Ahmed MJADI (mjadiahmed@gmail.com)
 * @brief Connect your ESP32 to the Accesspoint with the best signal
 * @version 0.2
 * @date 2022-01-17
 * @copyright Copyright (c) 2022
 */

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiMulti.h>

WiFiMulti wifiMulti;
String WiFiAP[6] = {"NXT-AP2", "2899100*-+", "NEXT-AP1", "2899100*-+", "NEXTRONIC-1", "Next2021"};

void setup()
{
  Serial.begin(9600);
  delay(10);

  // wifiMulti.addAP("NXT-AP2", "2899100*-+");
  // wifiMulti.addAP("NEXT-AP1", "2899100*-+");
  // wifiMulti.addAP("NEXTRONIC-1", "Next2021");
  /*setup  multi WiFi*/
  for (int i = 0; i < 5; i = i + 2)
  {
    Serial.println("[D] Wifi AP table #  " + String(WiFiAP[i].c_str()) + " | " + String(WiFiAP[i + 1].c_str()));
    wifiMulti.addAP(WiFiAP[i].c_str(), WiFiAP[i + 1].c_str());
    delay(1);
  }

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
