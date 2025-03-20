#pragma once

#include "ofMain.h"

class Particle {
public:
  void setup(float x, float y);
  void update();
  virtual void show();
  void applyForce(ofVec2f force);
  bool isDead();

  ofVec2f position;
  ofVec2f velocity;
  ofVec2f acceleration;
  float lifespan;
};
