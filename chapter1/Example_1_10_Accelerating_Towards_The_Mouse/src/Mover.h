#ifndef _MOVER
#define _MOVER

#include "ofMain.h"

class Mover {
public:
  void setup();
  void update();
  void show();

  ofVec2f position;
  ofVec2f velocity;
  ofVec2f acceleration;
  float topSpeed;
};

#endif
