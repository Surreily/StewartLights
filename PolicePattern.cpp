#include <Adafruit_NeoPixel.h>

#include "Pattern.h"
#include "PolicePattern.h"

PolicePattern::PolicePattern(int len, int color1, int color2) {

  // Set the length.
  _len = len;
  
  // Set the length.
  _color1 = color1;
  _color2 = color2;

  // Set the position.
  _frame = 0;
  
}

PolicePattern::~PolicePattern() {

  // Nothing.
  
}

void PolicePattern::draw(Adafruit_NeoPixel* strip) {

  // Increase the frame.
  _frame = (_frame+1)%32;

  // Select a color.
  if (_frame%4 >= 2) {
    for (int i=0; i<_len; i++) {
      strip->setPixelColor(i, 0, 0, 0);
    }
  } else {
    if (_frame >= 16) {
      for (int i=0; i<_len; i++) {
        strip->setPixelColor(i, wheel(strip, _color1));
      }
    } else {
      for (int i=0; i<_len; i++) {
        strip->setPixelColor(i, wheel(strip, _color2));
      }
    }
  }

  // Show the strip.
  strip->show();
  
}

