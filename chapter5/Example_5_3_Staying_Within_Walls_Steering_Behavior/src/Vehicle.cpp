#include "Vehicle.h"

void Vehicle::setup(float x, float y) {
  position = ofVec2f(x, y);
  velocity = ofVec2f(3, 4);
  acceleration = ofVec2f(0, 0);
  r = 6;
  maxSpeed = 3;
  maxForce = 0.15;
}

void Vehicle::update() {
  velocity += acceleration;
  velocity.limit(maxSpeed);
  position += velocity;

  acceleration *= 0;
}

void Vehicle::applyForce(ofVec2f force) { acceleration += force; }

void Vehicle::boundaries(float offset) {
  ofVec2f desired;

  if (position.x < offset) {
    desired = ofVec2f(maxSpeed, velocity.y);
  } else if (position.x > ofGetWidth() - offset) {
    desired = ofVec2f(-maxSpeed, velocity.y);
  }

  if (position.y < offset) {
    desired = ofVec2f(velocity.x, maxSpeed);
  } else if (position.y > ofGetHeight() - offset) {
    desired = ofVec2f(velocity.x, -maxSpeed);
  }

  if (desired.length() > 0) {
    desired.normalize();
    desired *= maxSpeed;

    ofVec2f steer = desired - velocity;
    steer.limit(maxForce);
    applyForce(steer);
  }
}

void Vehicle::show() {
  const float angle = ofVec2f(1, 0).angleRad(velocity);

  ofPushMatrix();

  ofTranslate(position.x, position.y);
  ofRotateRad(angle);

  ofSetLineWidth(2);

  ofFill();
  ofSetColor(127);
  ofBeginShape();
  ofVertex(r * 2, 0);
  ofVertex(-r * 2, -r);
  ofVertex(-r * 2, r);
  ofEndShape(true);

  ofNoFill();
  ofSetColor(0);
  ofBeginShape();
  ofVertex(r * 2, 0);
  ofVertex(-r * 2, -r);
  ofVertex(-r * 2, r);
  ofEndShape(true);

  ofPopMatrix();
}
