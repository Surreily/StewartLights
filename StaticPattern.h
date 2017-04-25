#ifndef STATICPATTERN_H
#define STATICPATTERN_H

#include <Adafruit_NeoPixel.h>

class StaticPattern : public Pattern {

  public:

    StaticPattern(int len, int color, int sweep = 0);
    ~StaticPattern();
    
    void draw(Adafruit_NeoPixel* strip);

  private:

    // The color.
    int _color;

    // The sweeping speed.
    int _sweep;
    int _sweepCounter;
  
};

#endif
