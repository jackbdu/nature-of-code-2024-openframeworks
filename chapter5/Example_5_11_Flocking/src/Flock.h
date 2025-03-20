#pragma once

#include "Boid.h"
#include "ofMain.h"

class Flock {
public:
  void setup();
  void update();
  void show();
  void addBoid(Boid *boid);

  vector<Boid *> boids;
};
