#include "Vehicle.h"

void Vehicle::setup(float x, float y) {
  position = ofVec2f(x, y);
  velocity = ofVec2f(0, 0);
  acceleration = ofVec2f(0, 0);
  r = 6;
  maxSpeed = 3;
  maxForce = 0.2;
}

void Vehicle::applyBehaviors(vector<Vehicle *> vehicles) {
  ofVec2f separateForce = separate(vehicles);
  ofVec2f seekForce = seek(ofVec2f(ofGetMouseX(), ofGetMouseY()));

  separateForce *= 1.5;
  seekForce *= 0.5;

  applyForce(separateForce);
  applyForce(seekForce);
}

void Vehicle::applyForce(ofVec2f force) { acceleration += force; }

ofVec2f Vehicle::separate(vector<Vehicle *> vehicles) {
  const float desiredSeparation = r * 2;
  ofVec2f sum;
  int count = 0;
  for (auto other : vehicles) {
    const float d = position.distance(other->position);
    if (this != other && d < desiredSeparation) {
      ofVec2f diff = position - other->position;
      diff.scale(1 / d);
      sum += diff;
      ++count;
    }
  }

  if (count > 0) {
    sum.scale(maxSpeed);
    ofVec2f steer = sum - velocity;
    steer.limit(maxForce);
  }

  return sum;
}

ofVec2f Vehicle::seek(ofVec2f target) {
  ofVec2f desired = target - position;
  desired.scale(maxSpeed);

  ofVec2f steer = desired - velocity;
  steer.limit(maxForce);

  return steer;
}

void Vehicle::update() {
  velocity += acceleration;
  velocity.limit(maxSpeed);
  position += velocity;

  acceleration *= 0;
}

void Vehicle::show() {
  ofPushMatrix();

  ofTranslate(position.x, position.y);

  ofSetLineWidth(2);

  ofSetColor(127);
  ofFill();
  ofDrawCircle(0, 0, r);

  ofSetColor(0);
  ofNoFill();
  ofDrawCircle(0, 0, r);

  ofPopMatrix();
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
