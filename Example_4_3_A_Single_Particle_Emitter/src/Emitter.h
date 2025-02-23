#ifndef _EMITTER
#define _EMITTER

#include "Particle.h"
#include "ofMain.h"

class Emitter {
public:
  void setup(float x, float y);
  void addParticle();
  void update();
  void show();

  ofVec2f origin;
  vector<Particle> particles;
};

#endif
