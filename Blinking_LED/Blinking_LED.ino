/*
Developer   - Sriram Venkata Krishna
Date        - 07-12-2025
Board       - NodeMCU ESP-32S - V1.1
*/

// Blinking LED

const int LED_Pin = 2;
const int Time_Delay = 1000;

void setup()
{
  pinMode(LED_Pin, OUTPUT);
}

void loop()
{
  digitalWrite(LED_Pin, HIGH);
  delay(Time_Delay);

  digitalWrite(LED_Pin, LOW);
  delay(Time_Delay);
}

