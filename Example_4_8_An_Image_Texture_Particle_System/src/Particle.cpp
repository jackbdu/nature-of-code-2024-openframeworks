#include "Particle.h"

void Particle::setup(float x, float y) {
  position = ofVec2f(x, y);
  const float vx = ofRandomGaussian(0.0, 0.3);
  const float vy = ofRandomGaussian(-1.0, 0.3);
  velocity = ofVec2f(vx, vy);
  acceleration = ofVec2f(0, 0);
  lifespan = 100;

  img.load("texture.png");
}

void Particle::update() {
  velocity += acceleration;
  position += velocity;
  acceleration *= 0;

  lifespan -= 2;
}

void Particle::show() {
  ofSetColor(255, lifespan);
  img.setAnchorPercent(0.5, 0.5);
  img.draw(position.x, position.y);
}

void Particle::applyForce(ofVec2f force) { acceleration += force; }

bool Particle::isDead() { return lifespan < 0; }
