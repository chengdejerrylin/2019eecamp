#include <FastLED.h>
#define LED_PIN 8
#define NUM_LEDS 8
#define BRIGHTNESS 30
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];
#define UPDATES_PER_SECOND 100

int text_ok = 0;
int a[] = {126, 144, 144, 144, 126};
int b[] = {254, 146, 146, 146, 108};
int c[] = {254, 130, 130, 130, 130};
int d[] = {254, 130, 130, 130, 124};
int e[] = {254, 146, 146, 146, 146};
int f[] = {254, 144, 144, 144, 128};
int g[] = {124, 130, 138, 138, 76};
int h[] = {254, 16, 16, 16, 254};
int i[] = {130, 250, 130};
int j[] = {12, 2, 2, 2, 252};
int k[] = {254, 16, 40, 68, 130};
int l[] = {254, 2, 2, 2, 2};
int m[] = {254, 64, 32, 64, 254};
int n[] = {254, 32, 16, 8, 254};
int o[] = {124, 130, 130, 130, 124};
int p[] = {254, 136, 136, 136, 112};
int q_letter[] = {124, 130, 138, 134, 126};
int r[] = {254, 144, 152, 148, 98};
int s[] = {100, 146, 146, 146, 76};
int t[] = {128, 128, 254, 128, 128};
int u[] = {252, 2, 2, 2, 252};
int v[] = {248, 4, 2, 4, 248};
int w[] = {254, 4, 8, 4, 254};
int x[] = {198, 40, 16, 40, 198};
int y[] = {224, 16, 14, 16, 224};
int z[] = {134, 138, 146, 162, 194};
int te[] = {3,48,192,48,3};
int eos[] = {0, 3, 2, 0};
int excl[] = {0, 250, 0};
int ques[] = {64, 128, 138, 144, 96};

float delayTime = 1;

//POV clock cariables
unsigned long currentMillis, elapsed_loop_counter, previousMillis;
unsigned long counter_1, current_count;

//Interruption varaibles to count rotation speed
//We create 4 variables to store the previous value of the input signal (if LOW or HIGH)
byte last_IN_state;     //Here we store the previous state on digital pin 13
float one_rot_time = 0; //Here we store the full rotation time
float time_per_deg = 0; //Here we store the time it takes to make one degree rotation

void setup()
{
  PCICR |= (1 << PCIE0);   //enable PCMSK0 scan
  PCMSK0 |= (1 << PCINT4); //Enable pin state interruption on pin D13

  //Output pins register configuration
  //DDRB |= B00000001;      //8 as output

  delay(3000); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  DDRB &= B11101111; //12 input

  //PORTB &= B10111110; //8 to 13 LOW
}

void draw_a_line(int this_line)
{
  for (int i = 0; i < 8; ++i)
  {
    leds[i] = this_line & (1 << i)?CRGB:: Red : CRGB::Black;
    //leds[i] = this_line & (1 << i);
  }
  FastLED.show();
}

void displayChar(char cr, float line_delay)
{
  if (cr == "1"){
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(te[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == 'a')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(a[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == 'b')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(b[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == 'c')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(c[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == 'd')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(d[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == 'e')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(e[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == 'f')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(f[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == 'g')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(g[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == 'h')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(h[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == 'i')
  {
    for (int itr = 0; itr < 3; itr++)
    {
      draw_a_line(i[itr]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == 'j')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(j[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == 'k')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(k[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == 'l')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(l[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == 'm')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(m[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == 'n')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(n[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == 'o')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(o[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == 'p')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(p[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == 'q')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(q_letter[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == 'r')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(r[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == 's')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(s[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == 't')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(t[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == 'u')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(u[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == 'v')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(v[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == 'w')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(w[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == 'x')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(x[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == 'y')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(y[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == 'z')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(z[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == '!')
  {
    for (int i = 0; i < 3; i++)
    {
      draw_a_line(excl[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == '?')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(ques[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  if (cr == '.')
  {
    for (int i = 0; i < 4; i++)
    {
      draw_a_line(eos[i]);
      delayMicroseconds(line_delay);
    }
    draw_a_line(0);
  }
  delayMicroseconds(line_delay * 2);
}

void displayString(char *s, float line_delay)
{
  for (int i = 0; i <= strlen(s); i++)
  {
    displayChar(s[i], line_delay);
  }
}

void loop()
{
  currentMillis = micros();
  elapsed_loop_counter = currentMillis - previousMillis;
  delayTime = time_per_deg *2 ; //we want 2 degrees for each line of the letters

  //This if here is to make sure I'll start printing at 216 deg so the text will be centered.
  if ((elapsed_loop_counter >= time_per_deg * (216)) && (elapsed_loop_counter < time_per_deg * (217)) && text_ok)
  {
    displayString("abcdefg", delayTime);
    //delayMicroseconds(delayTime*10);
    text_ok = 0;
  }

/*
  //This if here is to make sure I'll start printing at 216 deg so the text will be centered.
  currentMillis = micros();
  elapsed_loop_counter = currentMillis - previousMillis;
  delayTime = 2000;
  //if ((elapsed_loop_counter >= 10 * (216)) && (elapsed_loop_counter < 10 * (217)) && text_ok)
  //{
    displayString("ntuee", delayTime);
    //delayMicroseconds(delayTime*10);
    //text_ok = 0;
  //}*/
}

ISR(PCINT0_vect)
{
  //First we take the current count value in micro seconds using the micros() function

  current_count = micros();
  ///////////////////////////////////////Channel 1
  if (PINB & B00010000)
  { //We make an AND with the pin state register, We verify if pin 12 is HIGH???
    if (last_IN_state == 0)
    {                            //If the last state was 0, then we have a state change...
      last_IN_state = 1;         //Store the current state into the last state for the next loop
      counter_1 = current_count; //Set counter_1 to current value.
    }
  }
  else if (last_IN_state == 1)
  {                                           //If pin 8 is LOW and the last state was HIGH then we have a state change
    last_IN_state = 0;                        //Store the current state into the last state for the next loop
    one_rot_time = current_count - counter_1; //We make the time difference. Channel 1 is current_time - timer_1.
    time_per_deg = one_rot_time / 360.0;
    previousMillis = micros();
    text_ok = 1;
  }
}
