#ifndef STATICPATTERN_H
#define STATICPATTERN_H

#include <Adafruit_NeoPixel.h>

class StaticPattern : public Pattern {

  public:

    StaticPattern(int len, int color);
    ~StaticPattern();
    
    void draw(Adafruit_NeoPixel* strip);

  private:

    // The color.
    int _color;
  
};

#endif
