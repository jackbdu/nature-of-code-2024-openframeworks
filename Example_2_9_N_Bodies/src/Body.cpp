#include "Body.h"

void Body::setup(float x, float y, float m) {
  mass = m;
  radius = sqrt(mass) * 8;
  position = ofVec2f(x, y);
  velocity = ofVec2f(0, 0);
  acceleration = ofVec2f(0, 0);
}

ofVec2f Body::attract(Body body) {
  ofVec2f force = position - body.position;
  float distance = force.length();
  distance = ofClamp(distance, 5, 25);
  const float G = 1;
  const float strength = (G * (mass * body.mass)) / (distance * distance);
  force.scale(strength);
  return force;
}

void Body::applyForce(ofVec2f force) {
  const ofVec2f f = force / mass;
  acceleration += f;
}

void Body::update() {
  velocity += acceleration;
  position += velocity;
  acceleration *= 0;
}

void Body::show() {
  ofFill();
  ofSetColor(127, 100);
  ofDrawCircle(position.x, position.y, radius);

  ofNoFill();
  ofSetColor(0);
  ofSetLineWidth(2);
  ofDrawCircle(position.x, position.y, radius);
}
