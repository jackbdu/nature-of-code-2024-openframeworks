#include "Emitter.h"

void Emitter::setup(float x, float y) { origin = ofVec2f(x, y); }

void Emitter::addParticle() {
  Particle particle;
  particle.setup(origin.x, origin.y);
  particles.push_back(particle);
}

void Emitter::update() {
  for (int i = particles.size() - 1; i >= 0; --i) {
    auto particle = &particles[i];
    particle->update();
    if (particle->isDead()) {
      particles.erase(particles.begin() + i);
    }
  }

  /*
  for (Particle &particle : particles) {
    particle.update();
  }

  // https://openframeworks.cc//documentation/utils/ofUtils/#!show_ofRemove
  ofRemove(particles, [](Particle &p) { return p.isDead(); });
  */
}

void Emitter::show() {
  for (int i = particles.size() - 1; i >= 0; --i) {
    auto particle = &particles[i];
    particle->show();
  }
}
