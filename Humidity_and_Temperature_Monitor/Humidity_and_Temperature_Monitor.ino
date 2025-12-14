/*
Developer   - Sriram Venkata Krishna
Date        - 12-12-2025
Board       - NodeMCU ESP-32S = V1.1
*/

// DHT11 Sensor & OLED Display Module - Humidity and Temperature Monitor 

#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int Width = 128;
const int Height = 64;
const int Reset_Pin = -1;
const int DHT11_Pin = 4;
const int Time_Delay = 2000;

float Humidity, Temperature;

DHT My_DHT11(DHT11_Pin, DHT11);
Adafruit_SSD1306 Display(Width, Height, &Wire, Reset_Pin);

void Display_Data()
{
  Display.clearDisplay();
  Display.drawRect(0, 0, 128, 64, WHITE);
  Display.drawLine(0, 32, 127, 32, WHITE);

  Display.setTextSize(1);
  Display.setCursor(4, 3);
  Display.print(F("Humidity : "));
  Display.setTextSize(2);
  Display.setCursor(23, 14);
  Display.print(Humidity);
  Display.print(F(" %"));

  Display.setTextSize(1);
  Display.setCursor(4, 35);
  Display.print(F("Temperature : "));
  Display.setTextSize(2);
  Display.setCursor(23, 46);
  Display.print(Temperature);
  Display.print(F(" C"));

  Display.drawCircle(Display.getCursorX() - 17, Display.getCursorY() + 1, 2, WHITE);
  Display.display();
}

void setup() 
{
  Serial.begin(9600);
  My_DHT11.begin();

  if(!Display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("SSD1306 Allocation Failed");
  }

  Display.setTextColor(SSD1306_WHITE);
}

void loop() 
{
  Humidity = My_DHT11.readHumidity();
  Temperature = My_DHT11.readTemperature();

  if(isnan(Humidity) || isnan(Temperature))
  {
    Serial.println("Reading Failed");
  }
  else
  {
    Serial.print("Humidity : ");
    Serial.print(Humidity);
    Serial.print("%, Temperature : ");
    Serial.print(Temperature);
    Serial.println("°C");

    Display_Data();
  }

  delay(Time_Delay);
}