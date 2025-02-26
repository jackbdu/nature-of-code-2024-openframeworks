#include "Emitter.h"

void Emitter::setup(float x, float y) { origin = ofVec2f(x, y); }

void Emitter::addParticle() {
  Particle particle;
  particle.setup(origin.x, origin.y);
  particles.push_back(particle);
}

void Emitter::applyForce(ofVec2f force) {
  for (Particle &particle : particles) {
    particle.applyForce(force);
  }
}

void Emitter::applyRepeller(Repeller repeller) {
  for (Particle &particle : particles) {
    const ofVec2f force = repeller.repel(particle);
    particle.applyForce(force);
  }
}

void Emitter::update() {
  for (int i = particles.size() - 1; i >= 0; --i) {
    auto particle = &particles[i];
    particle->update();
    if (particle->isDead()) {
      particles.erase(particles.begin() + i);
    }
  }
}

void Emitter::show() {
  for (int i = particles.size() - 1; i >= 0; --i) {
    auto particle = &particles[i];
    particle->show();
  }
}
