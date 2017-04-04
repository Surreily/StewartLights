#include <Adafruit_NeoPixel.h>

#include "Pattern.h"
#include "FirePattern.h"

FirePattern::FirePattern(int len, int base, int range) {

  // Set the length.
  _len = len;

  // Set the base fire color and the range.
  _base = base;
  _range = range;

  // Initialize color array.
  _colors = new int[_len];

  // Set initial red, green, and blue values.
  for (int i=0; i<_len; i++) {
    _colors[i] = random(0, _range+1);
    _momentums[i] = random(-3, 4);
  }
  
}

FirePattern::~FirePattern() {

  // Delete the red, green, and blue arrays.
  delete _colors;
  delete _momentums;
  
}

void FirePattern::draw(Adafruit_NeoPixel* strip) {

  // Randomly change the fire.
  for (int i=0; i<_len; i++) {

    // Move each pixel.
    //_momentums[i] = constrain(_momentums[i] + random(-30, 31), -50, 50);
    _colors[i] = constrain(_colors[i] + random(-(_range/3), _range/3), 0, _range);
    //if (abs(_colors[i]-25) > 20) _momentums[i] = -_momentums[i];

    // Set the pixel.
    strip->setPixelColor(i, wheel(strip, ((_colors[i]+256+_base)-(_range/2))%256));
    
  }

  // Show the fire.
  strip->show();
  
}

