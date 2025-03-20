#include "Attractor.h"

void Attractor::setup() {
  G = 1;
  mass = 20;
  position = ofVec2f(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
}

ofVec2f Attractor::attract(Mover mover) {
  ofVec2f force = position - mover.position;
  float distance = force.length();
  distance = ofClamp(distance, 5, 25);

  const float strength = (G * mass * mover.mass) / (distance * distance);
  force.scale(strength);

  return force;
}

void Attractor::show() {
  ofFill();
  ofSetColor(175, 200);
  ofDrawCircle(position.x, position.y, mass);

  ofNoFill();
  ofSetColor(0);
  ofSetLineWidth(4);
  ofDrawCircle(position.x, position.y, mass);
}
