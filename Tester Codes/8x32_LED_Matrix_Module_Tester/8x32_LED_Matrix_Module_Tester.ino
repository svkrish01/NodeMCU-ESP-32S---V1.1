/*
Developer   - Sriram Venkata Krishna
Date        - 11-12-2025
Board       - NodeMCU ESP-32S - V1.1
*/

// 8*32 LED Matrix Module Tester

#include <LedControl.h>

const int DIN = 5;
const int CS = 18;
const int CLK = 19;
const int Time_Delay = 100;

int X, Y;

LedControl LED_Matrix(DIN, CLK, CS, 4);

void setup() 
{
  for(int Module = 0; Module < 4; Module++)
  {
    LED_Matrix.shutdown(Module, false);
    LED_Matrix.setIntensity(Module, 8);
    LED_Matrix.clearDisplay(Module);
  }
}

void loop() 
{
  for(int Module = 0; Module < 4 ;Module++)
  {
    for(int Row = 0; Row < 8; Row++)
    {
      for(int Column = 0; Column < 8; Column++)
      {
        LED_Matrix.setLed(Module, Row, Column, true);

        delay(Time_Delay);

        LED_Matrix.setLed(Module, Row, Column, false);
      }
    }
  }
}
