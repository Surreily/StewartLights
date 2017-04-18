#include <Adafruit_NeoPixel.h>

#include "PatternFactory.h"
#include "Pattern.h"

// Define pins.
#define STRIP_PIN 13
#define BUTTON_PIN 2

// Define strip length.
#define STRIP_LENGTH 30

// Define number of available patterns.
#define NUM_PATTERNS 8

// The LED strip.
Adafruit_NeoPixel* strip;

// The current pattern.
int index;
PatternFactory* pattFactory;
Pattern* patt;

// The button listen timer.
int buttonTimer = 0;

void setup() {

  // Initialize the button.
  pinMode(BUTTON_PIN, INPUT);
  
  // Initialize the strip.
  strip = new Adafruit_NeoPixel(30, STRIP_PIN, NEO_GRB + NEO_KHZ800);
  strip->begin();

  // Set up the current pattern.
  index = 0;
  pattFactory = new PatternFactory();
  patt = pattFactory->createPattern(index, STRIP_LENGTH);

}

void loop() {

  // Decrease the button timer.
  if (buttonTimer > 0)
    buttonTimer--;

  // Check for button press.
  if (digitalRead(BUTTON_PIN) == HIGH) {
    if (buttonTimer == 0) {
      index = (index + 1) % NUM_PATTERNS;
      delete patt;
      patt = pattFactory->createPattern(index, STRIP_LENGTH);
    }
    buttonTimer = 20;
  }

  // Draw the strip.
  patt->draw(strip);
  delay(50);

}
