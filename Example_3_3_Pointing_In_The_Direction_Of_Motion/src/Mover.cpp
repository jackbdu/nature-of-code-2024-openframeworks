#include "Mover.h"

void Mover::setup() {
  position = ofVec2f(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
  velocity = ofVec2f(0, 0);
  acceleration = ofVec2f(0, 0);
  topSpeed = 4;
}

void Mover::update() {
  ofVec2f mouse = ofVec2f(ofGetMouseX(), ofGetMouseY());
  ofVec2f dir = mouse - position;

  dir.normalize();

  dir *= 0.5;

  acceleration = dir;

  velocity += acceleration;
  velocity.limit(topSpeed);
  position += velocity;
}

void Mover::show() {
  const float angle = ofVec2f(1, 0).angleRad(velocity);

  ofPushMatrix();

  ofTranslate(position.x, position.y);
  ofRotateRad(angle);

  ofSetRectMode(OF_RECTMODE_CENTER);

  ofFill();
  ofSetColor(127);
  ofDrawRectangle(0, 0, 30, 10);

  ofNoFill();
  ofSetColor(0);
  ofSetLineWidth(2);
  ofDrawRectangle(0, 0, 30, 10);

  ofPopMatrix();
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
