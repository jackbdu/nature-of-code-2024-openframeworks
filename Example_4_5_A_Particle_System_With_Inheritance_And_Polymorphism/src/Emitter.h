#pragma once

#include "Confetti.h"
#include "Particle.h"
#include "ofMain.h"

class Emitter {
public:
  void setup(float x, float y);
  void addParticle();
  void update();
  void show();

  ofVec2f origin;
  vector<shared_ptr<Particle>> particles;
};
