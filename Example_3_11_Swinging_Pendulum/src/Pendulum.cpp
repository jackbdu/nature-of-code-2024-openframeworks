#include "Pendulum.h"

void Pendulum::setup(float x, float y, float r) {
  pivot = ofVec2f(x, y);
  bob = ofVec2f(0, 0);
  radius = r;
  angle = PI * 0.25;

  angleVelocity = 0;
  angleAcceleration = 0;
  damping = 0.995;
  ballRadius = 24;

  dragging = false;
}

void Pendulum::update() {
  if (!dragging) {
    const float gravity = 0.4;
    angleAcceleration = -1 * gravity / radius * sin(angle);

    angleVelocity += angleAcceleration;
    angle += angleVelocity;

    angleVelocity *= damping;
  }
}

void Pendulum::show() {
  const float bobX = radius * sin(angle);
  const float bobY = radius * cos(angle);
  bob.set(bobX, bobY);
  bob += pivot;

  ofSetLineWidth(2);

  ofSetColor(0);
  ofDrawLine(pivot.x, pivot.y, bob.x, bob.y);

  ofFill();
  ofSetColor(127);
  ofDrawCircle(bob.x, bob.y, ballRadius);

  ofNoFill();
  ofSetColor(0);
  ofDrawCircle(bob.x, bob.y, ballRadius);
}

void Pendulum::clicked(float mx, float my) {
  const float d = ofDist(mx, my, bob.x, bob.y);
  if (d < ballRadius) {
    dragging = true;
  }
}

void Pendulum::drag(float mx, float my) {
  if (dragging) {
    const ofVec2f diff = pivot - ofVec2f(mx, my);
    angle = atan2(-1 * diff.y, diff.x) - HALF_PI;
  }
}

void Pendulum::stopDragging() {
  angleVelocity = 0;
  dragging = false;
}
