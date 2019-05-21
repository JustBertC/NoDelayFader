#include "NoDelayFader.h"

/*
  Use NoDelayFader to fade a PWM pin up and down
*/

#define FADE_TIME 2000
#define DIR_UP 1
#define DIR_DOWN -1

NoDelayFader led1(GPIO, LED_BUILTIN);

int direction = DIR_UP;

void setup() {
  led1.begin();
  led1.setValue(1023);
}

void loop() {

  if (!led1.running()) {
    if (direction == DIR_UP) {
      led1.setFader(0, FADE_TIME);
      direction = DIR_DOWN;
    } else {
      led1.setFader(1023, FADE_TIME);
      direction = DIR_UP;
    }
  }
  led1.update();
}
