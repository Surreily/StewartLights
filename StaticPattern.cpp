#include <Adafruit_NeoPixel.h>

#include "Pattern.h"
#include "StaticPattern.h"

StaticPattern::StaticPattern(int len, int color, int sweep = 0) {

  // Set the length.
  _len = len;
  
  // Set the length.
  _color = color;

  // Set the sweep.
  _sweep = sweep;
  _sweepCounter = 0;
  
}

StaticPattern::~StaticPattern() {

  // Nothing.
  
}

void StaticPattern::draw(Adafruit_NeoPixel* strip) {

  // If sweep is not zero, increase the sweep counter.
  if (_sweep > 0) {
    
    _sweepCounter = (_sweepCounter + 1) % _sweep;

    if (_sweepCounter == _sweep-1) {
      _color = (_color + 1) % 256;
    }
    
  }

  // Set the pixels.
  for (int i=0; i<_len; i++) {
    strip->setPixelColor(i, wheel(strip, _color));
  }
  strip->show();
  
}

