#include "Pattern.h"
#include "RainbowPattern.h"

#include <Adafruit_NeoPixel.h>

void RainbowPattern::draw(Adafruit_NeoPixel* strip) {

  strip->setPixelColor(_pos, 64, 64, 64);
  strip->show();
  
}
