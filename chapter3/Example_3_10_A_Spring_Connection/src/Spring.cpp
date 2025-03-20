#include "Spring.h"

void Spring::setup(float x, float y, float length) {
  anchor = ofVec2f(x, y);
  restLength = length;
  k = 0.2;
}

void Spring::connect(Bob *bob) {
  const ofVec2f direction = bob->position - anchor;
  const float currentLength = direction.length();
  const float stretch = currentLength - restLength;

  const ofVec2f force = direction.getScaled(-1 * k * stretch);

  bob->applyForce(force);
};

void Spring::constrainLength(Bob *bob, float minLen, float maxLen) {
  ofVec2f direction = bob->position - anchor;
  const float length = direction.length();

  if (length < minLen) {
    direction.scale(minLen);
    bob->position = anchor + direction;
    bob->velocity *= 0;
  } else if (length > maxLen) {
    direction.scale(maxLen);
    bob->position = anchor + direction;
    bob->velocity *= 0;
  }
};

void Spring::show() {
  ofSetLineWidth(2);
  ofSetColor(127);
  ofFill();
  ofDrawCircle(anchor.x, anchor.y, 5);

  ofSetColor(0);
  ofNoFill();
  ofDrawCircle(anchor.x, anchor.y, 5);
}

void Spring::showLine(Bob *bob) {
  ofSetLineWidth(2);
  ofSetColor(127);
  ofSetColor(0);
  ofDrawLine(bob->position.x, bob->position.y, anchor.x, anchor.y);
}
