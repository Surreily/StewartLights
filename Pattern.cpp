#include <Adafruit_NeoPixel.h>

#include "Pattern.h"

void Pattern::draw(Adafruit_NeoPixel* strip) { 
  
}

uint32_t Pattern::wheel(Adafruit_NeoPixel* strip, int pos) {
  
  pos = 255 - (pos%255);
  
  if (pos < 85) {
    return strip->Color(255-pos*3, 0, pos*3);
  }
  
  if (pos < 170) {
    pos-=85;
    return strip->Color(0, pos*3, 255-pos*3);
  }
  
  pos-=170;
  return strip->Color(pos*3, 255-pos*3, 0);
  
}
