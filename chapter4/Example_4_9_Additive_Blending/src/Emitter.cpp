#include "Emitter.h"

void Emitter::setup(float x, float y, ofImage _img) {
  origin = ofVec2f(x, y);
  img = _img;
}

void Emitter::addParticle() {
  Particle particle;
  particle.setup(origin.x, origin.y, img);
  particles.push_back(particle);
}

void Emitter::applyForce(ofVec2f force) {
  for (Particle &particle : particles) {
    particle.applyForce(force);
  }
}

void Emitter::update() {
  for (Particle &particle : particles) {
    particle.update();
  }

  ofRemove(particles, [](Particle &p) { return p.isDead(); });
}

void Emitter::show() {
  for (Particle &particle : particles) {
    particle.show();
  }
}
