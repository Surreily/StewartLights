#include "PatternFactory.h"

#include <Arduino.h>

#include "Pattern.h"
#include "FirePattern.h"
#include "StaticPattern.h"

Pattern* PatternFactory::createPattern(int index, int len) {

  Serial.begin(9600);
  Serial.print("Hello\n");

  switch (index) {
    //case 0: return new FirePattern(len, 0, 30);
    //case 1: return new FirePattern(len, 180, 30);
    case 0: return new FirePattern(len, 0, 70, 1);
    case 1: return new FirePattern(len, 32, 70, 2);
    case 2: return new FirePattern(len, 64, 70, 4);
    case 3: return new FirePattern(len, 96, 70, 8);
    case 4: return new FirePattern(len, 128, 70, 16);
    case 5: return new FirePattern(len, 160, 70);
    case 6: return new FirePattern(len, 192, 70);
    case 7: return new FirePattern(len, 224, 70);
  }
  
}

