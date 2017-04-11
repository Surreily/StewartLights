#ifndef PATTERN_H
#define PATTERN_H

#include <Adafruit_NeoPixel.h>

class Pattern {

  public:

    // Draw the pixels.
    virtual void draw(Adafruit_NeoPixel* strip);

  protected:

    // Length of the strip.
    int _len;

    // Utility function to get a color wheel.
    uint32_t wheel(Adafruit_NeoPixel* strip, int pos);

    // Utility functions to get individual colors given a color wheel position.
    int wheelRed(int pos);
    int wheelGreen(int pos);
    int wheelBlue(int pos);
    
    
};

#endif
