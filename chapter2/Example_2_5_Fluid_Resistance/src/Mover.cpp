#include "Mover.h"

void Mover::setup(float x, float y, float m) {
  mass = m;
  radius = m * 8;
  position = ofVec2f(x, y);
  velocity = ofVec2f(0, 0);
  acceleration = ofVec2f(0, 0);
}

void Mover::applyForce(ofVec2f force) {
  const ofVec2f f = force / mass;
  acceleration += f;
}

void Mover::update() {
  velocity += acceleration;
  position += velocity;
  acceleration *= 0;
}

void Mover::show() {
  ofFill();
  ofSetColor(127, 127);
  ofDrawCircle(position.x, position.y, radius);

  ofNoFill();
  ofSetColor(0);
  ofSetLineWidth(2);
  ofDrawCircle(position.x, position.y, radius);
}

void Mover::checkEdges() {
  if (position.y > ofGetHeight() - radius) {
    position.y = ofGetHeight() - radius;
    velocity.y *= -0.9;
  }
}
