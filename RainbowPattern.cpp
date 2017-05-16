#include "RainbowPattern.h"

#include <Adafruit_NeoPixel.h>
#include "Core.h"
#include "Settings.h"

void rainbowPatternLoop(Adafruit_NeoPixel* strip, int spd) {

  int col = 0;
  int pos = 0;

  // Initialize the pattern.
  for (int i=1; i<STRIP_LENGTH; i++) {
    strip->setPixelColor(i, getColor(col));
    col = (col+spd)%256;
  }
  strip->show();

  while (!tick()) {

    // Set and show the pixel.
    strip->setPixelColor(pos, getColor(col));
    strip->show();

    // Increase the position and color.
    col = (col+spd)%256;
    pos = (pos+1)%STRIP_LENGTH;
    
  }
  
}

