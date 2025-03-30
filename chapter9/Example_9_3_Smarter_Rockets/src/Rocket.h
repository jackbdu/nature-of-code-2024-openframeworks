#pragma once

#include "DNA.h"
#include "Obstacle.h"
#include "ofMain.h"

class Rocket {
public:
  void setup(float x, float y, shared_ptr<DNA> _dna);
  void calculateFitness();
  void run(vector<Obstacle> obstacles);
  void checkObstacles(vector<Obstacle> obstacles);
  void checkTarget(Obstacle target);
  void applyForce(ofVec2f force);
  void update();
  void show();

  ofVec2f acceleration;
  ofVec2f velocity;
  ofVec2f position;
  shared_ptr<DNA> dna;
  float r;
  float fitness;
  float recordDistance;
  int finishCounter;
  int geneCounter;
  bool hitObstacle;
  bool hitTarget;
};
