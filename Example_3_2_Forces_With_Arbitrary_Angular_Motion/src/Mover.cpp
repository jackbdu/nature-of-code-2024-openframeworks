#include "Mover.h"

void Mover::setup(float x, float y, float m) {
  mass = m;
  radius = mass * 8;
  position = ofVec2f(x, y);
  angle = 0;
  angleVelocity = 0;
  angleAcceleration = 0;
  velocity = ofVec2f(ofRandom(-1, 1), ofRandom(-1, 1));
  acceleration = ofVec2f(0, 0);
}

void Mover::applyForce(ofVec2f force) {
  const ofVec2f f = force / mass;
  acceleration += f;
}

void Mover::update() {
  velocity += acceleration;
  position += velocity;

  angleAcceleration = acceleration.x / 10;
  angleVelocity += angleAcceleration;
  angleVelocity = ofClamp(angleVelocity, -0.1, 0.1);
  angle += angleVelocity;

  acceleration *= 0;
}

void Mover::show() {
  ofPushMatrix();

  ofTranslate(position.x, position.y);
  ofRotateRad(angle);

  ofFill();
  ofSetColor(127, 127);
  ofDrawCircle(0, 0, radius);

  ofNoFill();
  ofSetColor(0);
  ofSetLineWidth(2);
  ofDrawCircle(0, 0, radius);
  ofDrawLine(0, 0, radius, 0);

  ofPopMatrix();
}
