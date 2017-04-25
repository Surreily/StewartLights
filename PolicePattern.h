#ifndef POLICEPATTERN_H
#define POLICEPATTERN_H

#include <Adafruit_NeoPixel.h>

class PolicePattern : public Pattern {

  public:

    PolicePattern(int len, int color1, int color2);
    ~PolicePattern();
    
    void draw(Adafruit_NeoPixel* strip);

  private:

    // The colors.
    int _color1;
    int _color2;

    // The sweeping speed.
    int _frame;
  
};

#endif
