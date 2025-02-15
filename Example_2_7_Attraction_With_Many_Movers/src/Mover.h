#ifndef _MOVER
#define _MOVER

#include "ofMain.h"

class Mover {
public:
  void setup(float x, float y, float m);
  void applyForce(ofVec2f force);
  void update();
  void show();

  float mass;
  float radius;
  ofVec2f position;
  ofVec2f velocity;
  ofVec2f acceleration;
};

#endif
