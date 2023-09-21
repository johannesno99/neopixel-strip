#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 11
#define NUMPIXELS 32
#define DELAYVAL 500
Adafruit_NeoPixel NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int i = 0;
int k = 32;

void setup()
{
    Serial.begin(9600);
    NeoPixel.begin();
}

void loop()
{
    if (onoff_button_pressed() == true)
    { // hvis knappen er på, setter på lys
        if (delay_15() == true)
        {
            NeoPixel.setPixelColor(i, NeoPixel.Color(255, 0, 0));
            NeoPixel.show();
            i++;
            if (i >= 32)
            {
                i = 0;
            }
        }
    }
else
{ // skrur av hvis ikke
    if (onoff_button_pressed() == false)
    {
        if (delay_15() == true)
        {
            NeoPixel.setPixelColor(k, NeoPixel.Color(255, 0, 0));
            NeoPixel.show();
            k--;
            }
}
}
}

// variabler for av og på knapp, gul ledning:
int onoff_button = 8;
bool isButtonOn = false;

// variabler for knappens funksjoner
byte lastButtonState;
byte ledState = LOW;
unsigned long lastTimeButtonStateChanged = millis();
unsigned long debounceDuration = 50;

// funksjon for av og på knapp:
bool onoff_button_pressed()
{
    byte buttonState = digitalRead(onoff_button); // leser tilstand til knapp

    if (millis() - lastTimeButtonStateChanged >= debounceDuration)
    { // for å unngå debounce på knappen

        if (buttonState == 1 && lastButtonState == 0)
        {                                          // hvis knapp er på og tidligere av:
            lastTimeButtonStateChanged = millis(); // setter siste gang knapp byttte til millis
            isButtonOn = !isButtonOn;
        }
    }
    lastButtonState = buttonState;
    return isButtonOn;
}

// variabler for bruk av millis til delay på 500
unsigned long previous_time = 0;
const long blinkDelay_15 = 15;

// funksjon for delay på 15
bool delay_15()
{
    unsigned long current_time = millis();
    if (current_time - previous_time >= blinkDelay_15)
    {
        previous_time = current_time;
        return true;
    }
    else
    {
        return false;
    }
}
