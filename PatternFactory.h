#ifndef PATTERNFACTORY_H
#define PATTERNFACTORY_H

#include "Pattern.h"

class PatternFactory {

  public:

    Pattern* createPattern(int index, int len);
  
};

#endif
