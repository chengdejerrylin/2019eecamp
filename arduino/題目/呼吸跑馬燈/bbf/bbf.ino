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
    // 讓LED依序來回亮，亮暗的時候亮度遞增遞減
}
