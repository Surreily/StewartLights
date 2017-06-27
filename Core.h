#ifndef CORE_H
#define CORE_H

#include <Adafruit_NeoPixel.h>

// Define an RGB struct.
struct RGB {
  byte r;
  byte g;
  byte b;
};

// Delays the program and returns true if the button is pressed.
bool tick();

// Gets a given color (red --> green --> blue) from the given input (0 --> 255).
uint32_t getColor(int color);

RGB getWheelColor(int pos);

#endif
