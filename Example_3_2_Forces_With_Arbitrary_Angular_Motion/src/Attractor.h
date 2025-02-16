#ifndef _ATTRACTOR
#define _ATTRACTOR

#include "Mover.h"
#include "ofMain.h"

class Attractor {
public:
  void setup();
  void show();
  ofVec2f attract(Mover mover);

  float G;
  float mass;
  ofVec2f position;
};

#endif
