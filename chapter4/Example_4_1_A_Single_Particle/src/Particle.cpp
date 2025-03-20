#include "Particle.h"

void Particle::setup(float x, float y) {
  position = ofVec2f(x, y);
  velocity = ofVec2f(ofRandom(-1, 1), ofRandom(-2, 0));
  acceleration = ofVec2f(0, 0);
  lifespan = 255;
}

void Particle::update() {
  velocity += acceleration;
  position += velocity;
  lifespan -= 2;
  acceleration *= 0;
}

void Particle::show() {
  ofSetLineWidth(2);

  ofFill();
  ofSetColor(127, lifespan);
  ofDrawCircle(position.x, position.y, 4);

  ofNoFill();
  ofSetColor(0, lifespan);
  ofDrawCircle(position.x, position.y, 4);
}

void Particle::applyForce(ofVec2f force) { acceleration += force; }

bool Particle::isDead() { return lifespan < 0; }
