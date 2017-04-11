#include <Adafruit_NeoPixel.h>

#include "Pattern.h"
#include "StaticPattern.h"

StaticPattern::StaticPattern(int len, int color) {

  // Set the length.
  _len = len;
  
  // Set the length.
  _color = color;
  
}

StaticPattern::~StaticPattern() {

  // Nothing.
  
}

void StaticPattern::draw(Adafruit_NeoPixel* strip) {

  // Set the pixels.
  for (int i=0; i<_len; i++) {
    strip->setPixelColor(i, wheel(strip, _color));
  }
  strip->show();
  
}

