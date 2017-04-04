#ifndef FIREPATTERN_H
#define FIREPATTERN_H

class FirePattern : public Pattern {

  public:

    FirePattern(int len, int base, int range);
    ~FirePattern();
    
    void draw(Adafruit_NeoPixel* strip);

  private:

    // The base color and range of the fire.
    int _base;
    int _range;

    // The colors and momentums of each pixel.
    int* _colors;
    int* _momentums;
  
};

#endif
