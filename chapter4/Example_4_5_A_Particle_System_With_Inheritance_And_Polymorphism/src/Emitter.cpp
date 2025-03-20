#include "Emitter.h"

void Emitter::setup(float x, float y) { origin = ofVec2f(x, y); }

void Emitter::addParticle() {
  const float r = ofRandom(1);
  if (r < 0.5) {
    auto particle = make_shared<Particle>();
    particle->setup(origin.x, origin.y);
    particles.push_back(particle);
  } else {
    auto confetti = make_shared<Confetti>();
    confetti->setup(origin.x, origin.y);
    particles.push_back(confetti);
  }
}

void Emitter::update() {
  for (int i = particles.size() - 1; i >= 0; --i) {
    auto particle = particles[i];
    particle->update();
    if (particle->isDead()) {
      particles.erase(particles.begin() + i);
    }
  }
}

void Emitter::show() {
  for (auto particle : particles) {
    particle->show();
  }
}
