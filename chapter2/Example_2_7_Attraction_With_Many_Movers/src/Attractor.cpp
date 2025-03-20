#include "Attractor.h"

void Attractor::setup() {
  G = 1;
  mass = 20;
  position = ofVec2f(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
  dragOffset = ofVec2f(0, 0);
  dragging = false;
  rollover = false;
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
  if (dragging) {
    ofSetColor(50);
  } else if (rollover) {
    ofSetColor(100);
  } else {
    ofSetColor(175, 200);
  }
  ofDrawCircle(position.x, position.y, mass);

  ofNoFill();
  ofSetColor(0);
  ofSetLineWidth(4);
  ofDrawCircle(position.x, position.y, mass);
}

void Attractor::handlePress(float mx, float my) {
  const float d = ofDist(mx, my, position.x, position.y);
  if (d < mass) {
    dragging = true;
    dragOffset.x = position.x - mx;
    dragOffset.y = position.y - my;
  }
}
void Attractor::handleHover(float mx, float my) {
  const float d = ofDist(mx, my, position.x, position.y);
  if (d < mass) {
    rollover = true;
  } else {
    rollover = false;
  }
}
void Attractor::handleDrag(float mx, float my) {
  if (dragging) {
    position.x = mx + dragOffset.x;
    position.y = my + dragOffset.y;
  }
}
void Attractor::stopDragging() { dragging = false; }
