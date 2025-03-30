#pragma once

#include "DNA.h"
#include "ofMain.h"

class Rocket {
public:
  void setup(float x, float y, shared_ptr<DNA> _dna);
  void calculateFitness(ofVec2f target);
  void applyForce(ofVec2f force);
  void update();
  void show();

  ofVec2f acceleration;
  ofVec2f velocity;
  ofVec2f position;
  float r;
  float fitness;
  int geneCounter;
  shared_ptr<DNA> dna;
};
