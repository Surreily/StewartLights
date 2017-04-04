#ifndef RAINBOWPATTERN_H
#define RAINBOWPATTERN_H

#include <Adafruit_NeoPixel.h>

#include "Pattern.h"

class RainbowPattern : public Pattern {

  public:

    void draw(Adafruit_NeoPixel* strip);

  private:

    int _pos = 0;
  
};

#endif
