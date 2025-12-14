/*
Developer   - Sriram Venkata Krishna
Date        - 13-12-2025
Board       - NodeMCU ESP-32S = V1.1
*/

// OLED Display Module - Getting Started

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int Width = 128;
const int Height = 64;
const int LED_Pin = 2;
const int Reset_Pin = -1;
const int Time_Delay = 1000;
Adafruit_SSD1306 Display(Width, Height, &Wire, Reset_Pin);

void setup() 
{
  pinMode(LED_Pin, OUTPUT);
  Serial.begin(9600);

  if(!Display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  { 
    Serial.println("SSD1306 Allocation Failed");
  } 

  Display.setTextSize(1);
  Display.setTextColor(SSD1306_WHITE);
  Display.clearDisplay();
  Display.setCursor(0, 0);
  Display.println(F("Hello, World!"));
  Display.display();
}

void loop() 
{
  digitalWrite(LED_Pin, HIGH);
  delay(Time_Delay);

  digitalWrite(LED_Pin, LOW);
  delay(Time_Delay);
}