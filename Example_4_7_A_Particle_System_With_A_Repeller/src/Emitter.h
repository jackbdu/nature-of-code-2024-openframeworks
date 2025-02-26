#ifndef _EMITTER
#define _EMITTER

#include "Particle.h"
#include "Repeller.h"
#include "ofMain.h"

class Emitter {
public:
  void setup(float x, float y);
  void addParticle();
  void applyForce(ofVec2f force);
  void applyRepeller(Repeller repeller);
  void update();
  void show();

  ofVec2f origin;
  vector<Particle> particles;
};

#endif
