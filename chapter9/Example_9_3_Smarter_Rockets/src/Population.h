#pragma once

#include "Rocket.h"
#include "ofMain.h"

class Population {
public:
  void setup(float _mutationRate, int length, int lifeSpan);
  void live(vector<Obstacle> obstacles, Obstacle target);
  bool targetReached();
  void checkFitness();
  void selection();
  void reproduction();
  void show();
  shared_ptr<DNA> weightedSelection();

  float mutationRate;
  vector<Rocket> population;
  int generations;
};
