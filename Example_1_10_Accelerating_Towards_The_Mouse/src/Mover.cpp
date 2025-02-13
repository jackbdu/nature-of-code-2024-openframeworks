#include "Mover.h"

void Mover::setup() {
  position = ofVec2f(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
  topSpeed = 5;
}

void Mover::update() {
  ofVec2f mouse = ofVec2f(ofGetMouseX(), ofGetMouseY());
  ofVec2f dir = mouse - position;

  dir.normalize();

  dir *= 0.2;

  acceleration = dir;

  velocity += acceleration;
  velocity.limit(topSpeed);
  position += velocity;
}

void Mover::show() {
  const float r = 24;

  ofFill();
  ofSetColor(127);
  ofDrawCircle(position.x, position.y, r);

  ofNoFill();
  ofSetColor(0);
  ofSetLineWidth(2);
  ofDrawCircle(position.x, position.y, r);
}
