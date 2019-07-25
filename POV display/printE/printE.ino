#include <FastLED.h>
#define LED_PIN 8
#define NUM_LEDS 8
#define BRIGHTNESS 30
CRGB LEDs[NUM_LEDS];
#define UPDATES_PER_SECOND 100

byte e[] = {254, 146, 146, 146, 146};
// byte e[] = {B11111110, B10010010, B10010010, B10010010, B10010010};

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
  FastLED.addLeds<WS2812, LED_PIN, GRB>(LEDs, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  DDRB &= B11101111; //12 input

  //PORTB &= B10111110; //8 to 13 LOW
}

void draw_a_line(int this_line)
{
  LEDs[0] = this_line & 0b00000001 ? CRGB::Red : CRGB::Black;
  LEDs[1] = this_line & 0b00000010 ? CRGB::Red : CRGB::Black;
  LEDs[2] = this_line & 0b00000100 ? CRGB::Red : CRGB::Black;
  LEDs[3] = this_line & 0b00001000 ? CRGB::Red : CRGB::Black;
  LEDs[4] = this_line & 0b00010000 ? CRGB::Red : CRGB::Black;
  LEDs[5] = this_line & 0b00100000 ? CRGB::Red : CRGB::Black;
  LEDs[6] = this_line & 0b01000000 ? CRGB::Red : CRGB::Black;
  LEDs[7] = this_line & 0b10000000 ? CRGB::Red : CRGB::Black;
  FastLED.show();
}

void displayChar(char cr, float line_delay)
{
  
  if (cr == 'e')
  {
    for (int i = 0; i < 5; i++)
    {
      draw_a_line(e[i]);
    }
    draw_a_line(0);
  }
  
}

void displayString(const char *s, float line_delay)
{
  for (int i = 0; i < strlen(s); i++)
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
  if ((elapsed_loop_counter >= time_per_deg * (216)) && (elapsed_loop_counter < time_per_deg * (217)))
  {
    displayString("e", delayTime);
  }
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
  }
}
