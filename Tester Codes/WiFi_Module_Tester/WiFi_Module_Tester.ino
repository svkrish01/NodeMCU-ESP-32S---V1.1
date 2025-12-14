/*
Developer   - Sriram Venkata Krishna7
Date        - 07-12-2025
Board       - NodeMCU ESP-32S - V1.1
*/

// WiFi Module Tester

#include<WiFi.h>

const int LED_Pin = 2;
const int Time_Delay = 1000;

const char* SSID = "67";
const char* Password = "Never_Gonna_Give_You_Up";

void setup() 
{
  pinMode(LED_Pin, OUTPUT);

  Serial.begin(115200);
  delay(1000);

  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, Password);

  Serial.print("Connecting to WiFi...");

  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
  }

  Serial.println();
  Serial.println("Connected to WiFi");

  Serial.println(WiFi.localIP());
}

void loop() 
{
  digitalWrite(LED_Pin, HIGH);
  delay(Time_Delay);

  digitalWrite(LED_Pin, LOW);
  delay(Time_Delay);
}
