#ifndef _BODY
#define _BODY

#include "ofMain.h"

class Body {
public:
  void setup(float x, float y);
  void attract(Body *body);
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
