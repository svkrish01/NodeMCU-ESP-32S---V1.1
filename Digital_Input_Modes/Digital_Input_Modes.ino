/*
Developer   - Sriram Venkata Krishna
Date        - 09-12-2025
Board       - NodeMCU ESP-32S - V1.1
*/

// Digital Input Modes

const int Input_1 = 4;
const int Input_2 = 5;
const int Input_3 = 13;
const int Time_Delay = 1000;

int Value_1, Value_2, Value_3;

void setup() 
{
  pinMode(Input_1, INPUT);
  pinMode(Input_2, INPUT_PULLUP);
  pinMode(Input_3, INPUT_PULLDOWN);

  Serial.begin(115200);
}

void loop() 
{
  Value_1 = digitalRead(Input_1);
  Value_2 = digitalRead(Input_2);
  Value_3 = digitalRead(Input_3);

  Serial.print("Input 1 is : ");
  Serial.print(Value_1);

  Serial.print(", Input 2 is : ");
  Serial.print(Value_2);

  Serial.print(", Input 3 is : ");
  Serial.println(Value_3);

  delay(Time_Delay);
}
