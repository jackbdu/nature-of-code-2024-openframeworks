#include "Particle.h"

void Particle::setup(float x, float y) {
  position = ofVec2f(x, y);
  acceleration = ofVec2f(0, 0);
  velocity = ofVec2f(ofRandom(-1, 1), ofRandom(-2, 0));
  lifespan = 255;
  mass = 1;
}

void Particle::update() {
  velocity += acceleration;
  position += velocity;
  acceleration *= 0;

  lifespan -= 2;
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

void Particle::applyForce(ofVec2f force) {
  force /= mass;
  acceleration += force;
}

bool Particle::isDead() { return lifespan < 0; }
