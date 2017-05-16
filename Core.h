#ifndef CORE_H
#define CORE_H

#include <Adafruit_NeoPixel.h>

// Delays the program and returns true if the button is pressed.
bool tick();

// Gets a given color (red --> green --> blue) from the given input (0 --> 255).
uint32_t getColor(int color);

#endif
