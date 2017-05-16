#include "StaticPattern.h"

#include <Adafruit_NeoPixel.h>
#include "Core.h"
#include "Settings.h"

void staticPatternLoop(Adafruit_NeoPixel* strip, int col) {

  // Set the pixel colors.
  for (int i=0; i<STRIP_LENGTH; i++) {
    strip->setPixelColor(i, getColor(col));
    strip->show();
  }

  // Do nothing while this pattern is active.
  while (!tick()) {}
  
}

