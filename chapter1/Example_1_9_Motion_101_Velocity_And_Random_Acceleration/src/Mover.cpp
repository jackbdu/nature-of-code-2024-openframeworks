#include "Mover.h"

void Mover::setup() {
  position = ofVec2f(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
  topSpeed = 5;
}

void Mover::update() {
  acceleration = ofVec2f(2, 0);
  acceleration.rotateRad(ofRandom(TWO_PI));

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

void Mover::checkEdges() {
  if (position.x > ofGetWidth()) {
    position.x = 0;
  } else if (position.x < 0) {
    position.x = ofGetWidth();
  }

  if (position.y > ofGetHeight()) {
    position.y = 0;
  } else if (position.y < 0) {
    position.y = ofGetHeight();
  }
}
