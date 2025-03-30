#pragma once

#include "ofMain.h"

class DNA {
public:
  void setup(int lifeSpan);
  shared_ptr<DNA> crossover(shared_ptr<DNA> partner);
  void mutate(float mutationRate);

  vector<ofVec2f> genes;
  float maxForce;
};
