#include <Adafruit_NeoPixel.h>

#include "Pattern.h"
#include "FirePattern.h"
#include "StaticPattern.h"

// Define pins.
#define STRIP_PIN 13
#define BUTTON_PIN 9

// Define strip length.
#define STRIP_LENGTH 30

// The LED strip.
Adafruit_NeoPixel* strip;
Pattern* patt;

void setup() {
  
  // Initialize the strip.
  strip = new Adafruit_NeoPixel(30, STRIP_PIN, NEO_GRB + NEO_KHZ800);
  strip->begin();

  // Set up the current pattern.
  //patt = new FirePattern(STRIP_LENGTH, 30, 30);
  patt = new StaticPattern(STRIP_LENGTH, 200);

}

void loop() {

  patt->draw(strip);
  delay(50);

}
