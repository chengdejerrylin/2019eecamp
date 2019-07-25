   //////////////////////////////////////////////
  //        HALL EFFECT SENSOR DEMO           //
 //          Author: Nick Koumaris           //
//           http://www.educ8s.tv           //
/////////////////////////////////////////////
int hallSensorPin = 12;     
int ledPin =  8;    
int state = 0;
bool prev_state = 0;
unsigned long cctime = 0;
unsigned long current = 0,prev = 0;
void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);      
  pinMode(hallSensorPin, INPUT);     
}

void loop(){
  //Serial.println("cctime2q");
  state = digitalRead(hallSensorPin);
  Serial.println(state);
  if(prev_state != state) {
   if (state == LOW) {  // HIGH to LOW
      current = micros();
      cctime = current - prev;
      Serial.println(cctime);
      //Serial.println(current);
     
      digitalWrite(ledPin, HIGH); 
     prev_state = LOW;

   } 
   else { // LOW to HIGH
     Serial.println("cctime");
     digitalWrite(ledPin, LOW); 
      prev_state = HIGH;
   }
  }
  prev = current;
}
