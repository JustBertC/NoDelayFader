#include "NoDelayFader.h"

/*
  Use NoDelayFader to fade a PWM pin up and down.
  Using the Blynk app with buttons for V0 and V1 to fade up and down when pressed
*/

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "YourAuthToken";
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

#define FADE_TIME 2000

BlynkTimer timer;
NoDelayFader led1(GPIO, LED_BUILTIN);

void setup()
{
  Blynk.begin(auth, ssid, pass);
  led1.begin();
  timer.setInterval(10L, updateLed1);
  led1.setValue(1023);
}

void loop()
{
  Blynk.run();
  timer.run();
}

void updateLed1()
{
  led1.update();
}

BLYNK_WRITE(V0){
  if (param.asInt())
  {
    test1.setValue(0);
    test1.setFader(1023, FADE_TIME);
  }
}

BLYNK_WRITE(V1){
  if (param.asInt())
  {
    test1.setValue(1023);
    test1.setFader(0, FADE_TIME);
  }
}
