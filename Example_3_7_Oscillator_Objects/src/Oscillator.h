#ifndef _OSCILLATOR
#define _OSCILLATOR

#include "ofMain.h"

class Oscillator {
public:
  void setup();
  void update();
  void show();

  ofVec2f angle;
  ofVec2f angleVelocity;
  ofVec2f amplitude;
  float x;
  float y;
};

#endif
