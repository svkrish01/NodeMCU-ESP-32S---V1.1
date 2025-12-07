/*
Developer   - Sriram Venkata Krishna
Date        - 07-12-2025
Board       - NodeMCU ESP-32S - V1.1
*/

// Breathing LED

const int LED_Pin = 2;
const int Time_Delay = 10;

void setup()
{
  pinMode(LED_Pin, OUTPUT);
}

void loop()
{
  for(int X = 0; X <= 255; X++)
  {
    analogWrite(LED_Pin, X);

    delay(Time_Delay);
  }

  for(int X = 255; X >= 0; X--)
  {
    analogWrite(LED_Pin, X);

    delay(Time_Delay);
  }
}
