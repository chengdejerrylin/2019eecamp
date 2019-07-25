const byte LED = 10;
void setup() {
}

void loop()
{
    for(int i = 0; i < 256; i += 1) {
        analogWrite(LED, i);
        delay(10);
    }
    for(int i = 255; i >= 0; i -= 1) {
        analogWrite(LED, i);
        delay(10);
    }
}
