#include "Mover.h"

void Mover::setup() {
  mass = 1;
  position = ofVec2f(ofGetWidth() * 0.5, 30);
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

void Mover::display() {
  const float r = 24;

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
