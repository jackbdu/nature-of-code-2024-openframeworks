#include "Flock.h"

void Flock::setup() {}

void Flock::update(vector<vector<vector<Boid *>>> *grid, float resolution) {
  for (auto boid : boids) {
    boid->update(grid, resolution);
  }
}

void Flock::show() {
  for (auto boid : boids) {
    boid->show();
  }
}

void Flock::addBoid(Boid *boid) { boids.push_back(boid); }
