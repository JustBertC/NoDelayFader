#include "NoDelayFader.h"

/*
  Use NoDelayFader to fade a variable up and down and print to serial monitor
*/

#define FADE_TIME 2000
#define DIR_UP 1
#define DIR_DOWN -1

NoDelayFader varFader(VIRTUAL);

int direction = DIR_UP;

void setup() {
  Serial.begin(9600);
  varFader.begin();
  varFader.setValue(1023);
}

void loop() {

  if (!varFader.running()) {
    if (direction == DIR_UP) {
      varFader.setFader(0, FADE_TIME);
      direction = DIR_DOWN;
    } else {
      varFader.setFader(1023, FADE_TIME);
      direction = DIR_UP;
    }
  }

  Serial.println(varFader.currentValue());
  varFader.update();
}
