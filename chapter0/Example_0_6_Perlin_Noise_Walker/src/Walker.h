#ifndef _WALKER
#define _WALKER

#include "ofMain.h"

class Walker {
public:
  void setup();
  void show();
  void step();

  float x;
  float y;
  float tx;
  float ty;
};

#endif
