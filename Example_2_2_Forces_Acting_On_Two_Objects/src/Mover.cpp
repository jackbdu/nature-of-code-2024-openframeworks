#include "Mover.h"

void Mover::setup(float x, float y, float m) {
  mass = m;
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
  const float r = mass * 8;

  ofFill();
  ofSetColor(127, 127);
  ofDrawCircle(position.x, position.y, r);

  ofNoFill();
  ofSetColor(0);
  ofSetLineWidth(2);
  ofDrawCircle(position.x, position.y, r);
}

void Mover::checkEdges() {
  if (position.x > ofGetWidth()) {
    position.x = ofGetWidth();
    velocity.x *= -1;
  } else if (position.x < 0) {
    position.x = 0;
    velocity.x *= -1;
  }

  if (position.y > ofGetHeight()) {
    velocity.y *= -1;
    position.y = ofGetHeight();
  }
}
