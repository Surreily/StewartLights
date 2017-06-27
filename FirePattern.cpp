#include "FirePattern.h"

#include <Adafruit_NeoPixel.h>
#include "Core.h"
#include "Settings.h"

void firePatternLoop(Adafruit_NeoPixel* strip, int pos, int intensity) {

  // Get the desired color.
  RGB color = getWheelColor(pos);

  while (!tick()) {

    // Set the pixel colors.
    for (int i=0; i<STRIP_LENGTH; i++) {
  
      // Generate a random brightness.
      float brightness = random(256-intensity, 256)/256.0;
  
      // Show the pixel.
      strip->setPixelColor(i,
        (int) (color.r * brightness), 
        (int) (color.g * brightness), 
        (int) (color.b * brightness));
   
    }
  
    strip->show();
    
  }
  
}

