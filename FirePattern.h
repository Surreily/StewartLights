#ifndef FIREPATTERN_H
#define FIREPATTERN_H

class FirePattern : public Pattern {

  public:

    FirePattern(int len, int color, int range, int sweep = 0);
    ~FirePattern();
    
    void draw(Adafruit_NeoPixel* strip);

  private:

    // The range of the fire flicker.
    int _range;

    // The base color.
    int _color;
    int _r;
    int _g;
    int _b;

    // The sweeping speed.
    int _sweep;
    int _sweepCounter;

    // The brightnesses of each pixel.
    int* _brightnesses;
  
};

#endif
