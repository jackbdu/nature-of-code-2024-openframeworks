#include "Vehicle.h"

void Vehicle::setup(float x, float y, float _maxSpeed, float _maxForce) {
  position = ofVec2f(x, y);
  velocity = ofVec2f(0, 0);
  acceleration = ofVec2f(0, 0);
  r = 4;
  maxSpeed = _maxSpeed;
  maxForce = _maxForce;
}

void Vehicle::follow(FlowField flow) {
  ofVec2f desired = flow.lookup(position);
  desired *= maxSpeed;

  ofVec2f steer = desired - velocity;
  steer.limit(maxForce);
  applyForce(steer);
}

void Vehicle::applyForce(ofVec2f force) { acceleration += force; }

void Vehicle::update() {
  velocity += acceleration;
  velocity.limit(maxSpeed);
  position += velocity;
  acceleration *= 0;

  borders();
}

void Vehicle::borders() {
  if (position.x < -r)
    position.x = ofGetWidth() + r;
  if (position.y < -r)
    position.y = ofGetHeight() + r;
  if (position.x > ofGetWidth() + r)
    position.x = -r;
  if (position.y > ofGetHeight() + r)
    position.y = -r;
}

void Vehicle::show() {
  const float theta = ofVec2f(1, 0).angleRad(velocity);

  ofPushMatrix();

  ofTranslate(position.x, position.y);
  ofRotateRad(theta);

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
