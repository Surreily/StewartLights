#include <Adafruit_NeoPixel.h>

// General includes.
#include "Core.h"
#include "Settings.h"

// Pattern includes.
#include "StaticPattern.h"
#include "RainbowPattern.h"
#include "FirePattern.h"

// The LED strip.
Adafruit_NeoPixel* strip;

void setup() {

  // Initialize the button.
  pinMode(BUTTON_PIN, INPUT);
  
  // Initialize the strip.
  strip = new Adafruit_NeoPixel(30, STRIP_PIN, NEO_RGB + NEO_KHZ800);
  strip->setBrightness(STRIP_BRIGHTNESS);
  strip->begin();
  
}

void loop() {

  // Call the patterns in sequence.
  firePatternLoop(strip, 0, 224);
  firePatternLoop(strip, 43, 224);
  firePatternLoop(strip, 85, 224);
  firePatternLoop(strip, 128, 224);
  firePatternLoop(strip, 171, 224);
  firePatternLoop(strip, 213, 224);
  staticPatternLoop(strip, 0);
  staticPatternLoop(strip, 43);
  staticPatternLoop(strip, 85);
  staticPatternLoop(strip, 128);
  staticPatternLoop(strip, 171);
  staticPatternLoop(strip, 213);
  rainbowPatternLoop(strip, 1);
  rainbowPatternLoop(strip, 2);
  rainbowPatternLoop(strip, 4);
  rainbowPatternLoop(strip, 8);
  rainbowPatternLoop(strip, 16);

}
