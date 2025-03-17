#include "Flock.h"

void Flock::setup() {}

void Flock::update() {
  for (auto boid : boids) {
    boid->update(boids);
  }
}

void Flock::show() {
  for (auto boid : boids) {
    boid->show();
  }
}

void Flock::addBoid(Boid *boid) { boids.push_back(boid); }
