#include "Confetti.h"

void Confetti::show() {
  const float angle = ofMap(position.x, 0, ofGetWidth(), 0, TWO_PI * 2);

  ofPushMatrix();

  ofSetRectMode(OF_RECTMODE_CENTER);
  ofSetLineWidth(2);

  ofTranslate(position.x, position.y);
  ofRotateRad(angle);

  ofFill();
  ofSetColor(127, lifespan);
  ofDrawRectangle(0, 0, 12, 12);

  ofNoFill();
  ofSetColor(0, lifespan);
  ofDrawRectangle(0, 0, 12, 12);

  ofPopMatrix();
}
