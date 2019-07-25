const byte threshold = 180;
const byte pin[4] = {6, 9, 10, 11};
int brightness[4];

void darken(int index)
{
    brightness[index] -= 1;
    if (brightness[index] < 1)
        brightness[index] = 0;
}

void setup()
{
    for (byte i = 0; i < 4; i += 1) {
        pinMode(pin[i], OUTPUT);
    }
}

void loop()
{
    for(byte i = 0; i < 4; i += 1) {
        brightness[i] = 255;
    }
    for (byte i = 0; brightness[3] > 0; ) {
        for(int j = i; j >= 0; j -= 1) {
            analogWrite(pin[j], brightness[j]);
            darken(j);
        }
        if (brightness[i] == threshold && i < 3)
            i += 1;
        delay(2);
    }
    delay(300);
    for(byte i = 0; i < 4; i += 1) {
        brightness[i] = 255;
    }
    for (byte i = 0; brightness[3] > 0; ) {
        for(int j = i; j >= 0; j -= 1) {
            analogWrite(pin[3 - j], brightness[j]);
            darken(j);
        }
        if (brightness[i] == threshold && i < 3)
            i += 1;
        delay(2);
    }
    delay(300);
}
