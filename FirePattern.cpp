#include <Adafruit_NeoPixel.h>

#include "Pattern.h"
#include "FirePattern.h"

FirePattern::FirePattern(int len, int color, int range, int sweep = 0) {

  // Set the length.
  _len = len;

  // Set the color.
  _color = color;
  _r = wheelRed(color);
  _g = wheelGreen(color);
  _b = wheelBlue(color);

  // Set the range.
  _range = range;

  // Set the sweep.
  _sweep = sweep;
  _sweepCounter = 0;

  // Initialize brightnesses array.
  _brightnesses = new int[_len];

  // Set initial brightnesses.
  for (int i=0; i<_len; i++) {
    _brightnesses[i] = random(100-_range, 100);
  }
  
}

FirePattern::~FirePattern() {

  // Delete the red, green, and blue arrays.
  delete _brightnesses;
  
}

void FirePattern::draw(Adafruit_NeoPixel* strip) {

  // Randomly change the fire.
  for (int i=0; i<_len; i++) {

    // If sweep is not zero, increase the sweep counter.
    if (_sweep > 0) {
      
      _sweepCounter = (_sweepCounter + 1) % _sweep;

      if (_sweepCounter == _sweep-1) {
        _color = (_color + 1) % 256;
        //_r = wheelRed(_color);
        //_g = wheelGreen(_color);
        //_b = wheelBlue(_color);
      }
      
    }

    // Randomly change each pixel slightly.
    int randomColor = (256+_color+random(-2, 3))%256;
    _r = wheelRed(randomColor);
    _g = wheelGreen(randomColor);
    _b = wheelBlue(randomColor);

    // Move each pixel.
    _brightnesses[i] = constrain(_brightnesses[i] + random(-(_range/3), _range/3), 100-_range, 100);

    // Set the pixel.
    strip->setPixelColor(i, 
      ceil((float)_r/100.0*(float)_brightnesses[i]),
      ceil((float)_g/100.0*(float)_brightnesses[i]),
      ceil((float)_b/100.0*(float)_brightnesses[i]));
    
  }

  // Show the pixels.
  strip->show();
  
}

