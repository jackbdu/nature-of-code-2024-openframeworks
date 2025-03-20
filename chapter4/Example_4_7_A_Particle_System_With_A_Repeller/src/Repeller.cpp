#include "Repeller.h"

void Repeller::setup(float x, float y) {
  position = ofVec2f(x, y);
  power = 150;
}

void Repeller::show() {
  ofSetLineWidth(2);

  ofFill();
  ofSetColor(127);
  ofDrawCircle(position.x, position.y, 16);

  ofNoFill();
  ofSetColor(0);
  ofDrawCircle(position.x, position.y, 16);
}

ofVec2f Repeller::repel(Particle particle) {
  ofVec2f force = position - particle.position;
  float distance = force.length();
  distance = ofClamp(distance, 5, 50);
  const float strength = (-1 * power) / (distance * distance);

  force.scale(strength);

  return force;
}
