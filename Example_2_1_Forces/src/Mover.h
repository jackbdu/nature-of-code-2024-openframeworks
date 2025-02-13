#ifndef _MOVER
#define _MOVER

#include "ofMain.h"

class Mover {
public:
  void setup();
  void applyForce(ofVec2f force);
  void update();
  void display();
  void checkEdges();

  float mass;
  ofVec2f position;
  ofVec2f velocity;
  ofVec2f acceleration;
};

#endif
