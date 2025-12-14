/*
Developer   - Sriram Venkata Krishna
Date        - 11-12-2025
Board       - NodeMCU ESP-32S - V1.1
*/

// 8*8 LED Matrix Module Tester

#include <LedControl.h>

const int DIN = 5;
const int CS = 18;
const int CLK = 19;
const int Time_Delay = 100;

int X, Y;

LedControl LED_Matrix(DIN, CLK, CS, 1);

void setup() 
{
  LED_Matrix.shutdown(0, false);
  LED_Matrix.setIntensity(0, 8);
  LED_Matrix.clearDisplay(0);
}

void loop() 
{
  for(int Row = 0; Row < 8; Row++)
  {
    for(int Column = 0; Column < 8; Column++)
    {
      LED_Matrix.setLed(0, Row, Column, true);

      delay(Time_Delay);

      LED_Matrix.setLed(0, Row, Column, false);
    }
  }
}
