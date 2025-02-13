#include "Mover.h"

void Mover::setup() {
  position = ofVec2f(ofRandomWidth(), ofRandomHeight());
  velocity = ofVec2f(ofRandom(-2, 2), ofRandom(-2, 2));
}

void Mover::update() { position += velocity; }

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
