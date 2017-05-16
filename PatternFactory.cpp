#include "PatternFactory.h"

#include <Arduino.h>

#include "Pattern.h"
#include "FirePattern.h"
#include "StaticPattern.h"
#include "PolicePattern.h"

Pattern* PatternFactory::createPattern(int index, int len) {

  switch (index) {
    //case 0: return new FirePattern(len, 0, 30);
    //case 1: return new FirePattern(len, 180, 30);

    // Fire
    case 0: return new FirePattern(len, 0, 70);
    case 1: return new FirePattern(len, 31, 70);
    case 2: return new FirePattern(len, 0, 70);
    case 3: return new FirePattern(len, 31, 70);
    case 4: return new FirePattern(len, 127, 70);
    case 5: return new FirePattern(len, 159, 70);
    case 6: return new FirePattern(len, 191, 70);
    case 7: return new FirePattern(len, 223, 70);

    // Sweeping fire
    case 8: return new FirePattern(len, 0, 70, 2);
    case 9: return new FirePattern(len, 0, 70, 8);
    case 10: return new FirePattern(len, 0, 70, 32);
    case 11: return new FirePattern(len, 0, 70, 128);

    // Static
    case 12: return new StaticPattern(len, 0);
    case 13: return new StaticPattern(len, 31);
    case 14: return new StaticPattern(len, 63);
    case 15: return new StaticPattern(len, 95);
    case 16: return new StaticPattern(len, 127);
    case 17: return new StaticPattern(len, 159);
    case 18: return new StaticPattern(len, 191);
    case 19: return new StaticPattern(len, 223);

    // Sweeping static
    case 20: return new StaticPattern(len, 0, 2);
    case 21: return new StaticPattern(len, 0, 8);
    case 22: return new StaticPattern(len, 0, 32);
    case 23: return new StaticPattern(len, 0, 128);

    // Novelty patterns
    case 24: return new PolicePattern(len, 0, 160);
    
  }
  
}

