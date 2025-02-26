#ifndef _REPELLER
#define _REPELLER

#include "Particle.h"
#include "ofMain.h"

class Repeller {
public:
  void setup(float x, float y);
  void show();
  ofVec2f repel(Particle particle);

  ofVec2f position;
  float power;
};

#endif
