#include "Core.h"

#include <Adafruit_NeoPixel.h>
#include "Settings.h"

// The button timer.
int buttonTimer = 0;

bool tick() {

  // Delay for a period of time.
  delay(DELAY_PERIOD);

  // Decrease the button timer.
  if (buttonTimer > 0)
    buttonTimer--;

  // Return true if the button is pressed.
  if (digitalRead(BUTTON_PIN) == HIGH) {
    if (buttonTimer == 0) {
      buttonTimer = MINIMUM_BUTTON_CYCLES;
      return true;
    }
  }

  // Otherwise, return false.
  return false;
  
}

uint32_t getColor(int color) {

  color = 255 - (color%255);
  
  if (color < 85) {
    return (
      (uint32_t) (255-color*3) << 16 | 
      (uint32_t) 0 << 8 |
      (uint32_t) (color*3)
    );
  }
  
  if (color < 170) {
    color-=85;
    return (
      (uint32_t) 0 << 16 |
      (uint32_t) (color*3) << 8 |
      (uint32_t) (255-color*3)
    );
  }
  
  color-=170;
  return (
    (uint32_t) (color*3) << 16 |
    (uint32_t) (255-color*3) << 8
  );
  
}

RGB getWheelColor(int pos) {

  pos = (pos+255)%255;

  if (pos < 85) {
    return {255-pos*3, 0, pos*3};
  } else if (pos < 170) {
    pos -= 85;
    return {0, pos*3, 255-pos*3};
  } else {
    pos -= 170;
    return {pos*3, 255-pos*3, 0};
  }
  
}

