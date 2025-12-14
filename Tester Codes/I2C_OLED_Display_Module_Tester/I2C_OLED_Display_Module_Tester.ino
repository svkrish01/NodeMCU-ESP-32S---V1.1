/*
Developer   - Sriram Venkata Krishna
Date        - 12-12-2025
Board       - NodeMCU ESP-32S = V1.1
*/

// I2C OLED Display Module - Getting Started

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int Width = 128;
const int Height = 64;
const int Reset_Pin = -1;
const int Time_Delay = 100;

Adafruit_SSD1306 Display(Width, Height, &Wire, Reset_Pin);

void setup() 
{
  Serial.begin(9600);

  if(!Display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("SSD1306 Allocation Failed");
  }

  Display.setTextSize(1);
  Display.setTextColor(SSD1306_WH
NEW SKETCH
ITE);
}

void loop() 
{
  for(int Row = 0; Row < 64; Row++)
  {
    Display.clearDisplay();
    Display.drawLine(0, Row, 127, Row, WHITE);
    Display.display();

    delay(Time_Delay);
  }
}
