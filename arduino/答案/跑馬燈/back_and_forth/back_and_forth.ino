const byte pin[] = {9, 10, 11, 12};
void setup()
{
    for (int i = 0; i < 4; i += 1)
    { // 四個LED。
        pinMode(pin[i], OUTPUT);
        digitalWrite(pin[i], LOW); // 關閉所有LED。
    }
}
void loop()
{
    for (int i = 0; i < 4; i += 1)
    {
        digitalWrite(pin[i], HIGH);
        delay(1000);
        digitalWrite(pin[i], LOW);
    }
    for (int i = 3; i >= 0; i -= 1)
    {
        digitalWrite(pin[i], HIGH);
        delay(1000);
        digitalWrite(pin[i], LOW);
    }
}
