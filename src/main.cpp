#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>

const char* ssid     = "NAME";
const char* password = "PASSWORD";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 0, 60000); // 0 = UTC offset in seconds, 60000 = update interval in ms

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi connected");

  timeClient.begin(); // start NTP client
}

void loop() {
  timeClient.update(); // request current time from server

  unsigned long epochTime = timeClient.getEpochTime(); // seconds since 1970
  Serial.print("Epoch time: ");
  Serial.println(epochTime);

  Serial.print("Formatted time: ");
  Serial.println(timeClient.getFormattedTime()); // HH:MM:SS

  delay(1000);
}
