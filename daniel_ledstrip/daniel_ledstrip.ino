#include <Adafruit_NeoPixel.h>


//#define BUTTON1_PIN 
//#define BUTTON2_PIN3
#define PIN_NEO_PIXEL 11  
#define NUM_PIXELS 32
Adafruit_NeoPixel strip(NUM_PIXELS, PIN_NEO_PIXEL, NEO_GRB + NEO_KHZ800);

const int light_sensor = A1;
float light;
int light_value;
int led_array[]={2, 4, 7, 8, 11, 13}; 
int amt_led = 6; 
int digitalread[]={2, 4, 7, 8, 11, 13};
int a = 0;
int b = 0;
int c = 0;

int button1pin = 3;
int button2pin = 5;
int button3pin = 6;
int button1New;
int button2New;
int button3New;
int button1Old;
int button2Old;
int button3Old;
int counter1 = 0;
int counter2 = 0;
int counter3 = 0;
int LEDstate = digitalRead(13);
int LEDstate2 = digitalRead(11);
int LEDstate3 = digitalRead(8);


void setup()
{
 
    pinMode(3, INPUT);
    pinMode(5, INPUT);
    pinMode(6, INPUT);
    pinMode(light_sensor, INPUT);
    Serial.begin(9600);
  
}


  
void loop() { 
/*but1();  
  if (counter1 == 1){
but2();
but3();
COLOR();
running();
running2();
sensor();
  }
else 
  strip.clear();
  strip.show();
}*/
strip.fill(100);
strip.show();
}


void but1(){
  button1New=digitalRead(button1pin);
  if (button1Old == 0 && button1New == 1){
    if (LEDstate == 0) {
      counter1=counter1+1;
      LEDstate = 1;
    }
    else {
      
       counter1=counter1+1;
       LEDstate = 0;
       
      }}
button1Old=button1New;
  if (counter1 >1){
    counter1=0;
  }}


void but2(){
  button2New=digitalRead(button2pin);
  if (button2Old == 0 && button2New == 1){
    if (LEDstate2 == 0) {
      counter2=counter2+1;
      LEDstate2 = 1;
    }
    else {
      
       counter2=counter2+1;
       LEDstate2 = 0;
       
      }}
button2Old=button2New;
  if (counter2 >2){
    counter2=0;
  }}

void but3(){
  button3New=digitalRead(button3pin);
  if (button3Old == 0 && button3New == 1){
    if (LEDstate3 == 0) {
      counter3=counter3+1;
      LEDstate3 = 1;
    }
    else {
      
       counter3=counter3+1;
       LEDstate3 = 0;
       
      }}
button3Old=button3New;
  if (counter3 >2){
    counter3=0;
  }}
  
  void COLOR(){
  if (counter2 == 0){
    a=255;  
    b=150;   
    c=0;
}
  else if (counter2 == 1){
    a=0;
    b=255;
    c=255;
}
  else if (counter2 == 2){
    a=180;
    b=0;
    c=255;
}  
 
  }



void running() {
  
  if (counter3 == 0){
  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {          
    strip.setPixelColor(pixel, strip.Color(a, b, c));  
    strip.show();
    delay(100);
    strip.clear();
  }}

}


void running2() {
  
  if (counter3 == 1){
   
  for (int pixel = 6; pixel > NUM_PIXELS-7; pixel--) {          
    strip.setPixelColor(pixel, strip.Color(a, b, c));  
    strip.show();
    delay(100);
    strip.clear();
  }}}

void sensor(){
  if (counter3 ==2){
    int light_value = analogRead(light_sensor);
    light = light_value;
    delay(100);
    if (light_value > 1005) {
    a = 250;
    b = 0;
    c = 0;
    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {          
    strip.setPixelColor(pixel, strip.Color(a, b, c));  
    strip.show();
    delay(100);
    strip.clear();
    
    
    }}
    if (light_value < 1005){
    
    a = 0;
    b = 0;
    c = 255;
   
    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {          
    strip.setPixelColor(pixel, strip.Color(a, b, c));  
    strip.show();
      

   
    
    }}}}