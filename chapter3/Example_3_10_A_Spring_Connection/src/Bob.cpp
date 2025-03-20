#include "Bob.h"

void Bob::setup(float x, float y) {
  position = ofVec2f(x, y);
  velocity = ofVec2f(0, 0);
  acceleration = ofVec2f(0, 0);
  mass = 24;
  damping = 0.98;
  dragOffset = ofVec2f(0, 0);
  dragging = false;
}

void Bob::update() {
  velocity += acceleration;
  velocity *= damping;
  position += velocity;
  acceleration *= 0;
}

void Bob::applyForce(ofVec2f force) {
  ofVec2f f = force;
  f /= mass;
  acceleration += f;
}

void Bob::show() {
  ofSetLineWidth(2);

  ofFill();
  ofSetColor(127);
  if (dragging) {
    ofSetColor(200);
  }
  ofDrawCircle(position.x, position.y, mass);

  ofNoFill();
  ofSetColor(0);
  ofDrawCircle(position.x, position.y, mass);
}

void Bob::handleClick(float mx, float my) {
  const float d = ofDist(mx, my, position.x, position.y);
  if (d < mass) {
    dragging = true;
    dragOffset.x = position.x - mx;
    dragOffset.y = position.y - my;
  }
}

void Bob::handleDrag(float mx, float my) {
  if (dragging) {
    position.x = mx + dragOffset.x;
    position.y = my + dragOffset.y;
  }
}

void Bob::stopDragging() { dragging = false; }
