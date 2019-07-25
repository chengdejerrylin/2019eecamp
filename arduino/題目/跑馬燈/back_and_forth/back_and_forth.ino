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
    // 讓LED依序向左亮
    // 再讓LED依序向右亮
}
