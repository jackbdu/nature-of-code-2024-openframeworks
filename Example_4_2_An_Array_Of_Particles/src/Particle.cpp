#include "Particle.h"

void Particle::setup(float x, float y) {
  position = ofVec2f(x, y);
  acceleration = ofVec2f(0, 0);
  velocity = ofVec2f(ofRandom(-1, 1), ofRandom(-1, 0));
  lifespan = 255;
}

void Particle::update() {
  const ofVec2f gravity = ofVec2f(0, 0.05);
  applyForce(gravity);

  velocity += acceleration;
  position += velocity;
  lifespan -= 2;
  acceleration *= 0;
}

void Particle::show() {
  ofSetLineWidth(2);

  ofFill();
  ofSetColor(127);
  ofDrawCircle(position.x, position.y, 4);

  ofNoFill();
  ofSetColor(0);
  ofDrawCircle(position.x, position.y, 4);
}

void Particle::applyForce(ofVec2f force) { acceleration += force; }

bool Particle::isDead() { return lifespan < 0; }
