#pragma once

#include "Boid.h"
#include "ofMain.h"

class Flock {
public:
  void setup();
  void update(vector<vector<vector<Boid *>>> *grid, float resolution);
  void show();
  void addBoid(Boid *boid);

  vector<Boid *> boids;
};
