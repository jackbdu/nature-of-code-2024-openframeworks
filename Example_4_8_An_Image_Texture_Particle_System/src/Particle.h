#ifndef _PARTICLE
#define _PARTICLE

#include "ofMain.h"

class Particle {
public:
  void setup(float x, float y);
  void update();
  void show();
  void applyForce(ofVec2f force);
  bool isDead();

  ofFbo fbo;
  ofImage img;
  ofVec2f position;
  ofVec2f velocity;
  ofVec2f acceleration;
  float lifespan;
};

#endif
