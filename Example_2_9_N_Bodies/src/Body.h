#ifndef _BODY
#define _BODY

#include "ofMain.h"

class Body {
public:
  void setup(float x, float y, float m);
  void applyForce(ofVec2f force);
  void update();
  void show();
  ofVec2f attract(Body body);

  float mass;
  float radius;
  ofVec2f position;
  ofVec2f velocity;
  ofVec2f acceleration;
};

#endif
