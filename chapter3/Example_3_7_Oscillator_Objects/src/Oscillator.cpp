#include "Oscillator.h"

void Oscillator::setup() {
  angle = ofVec2f(0, 0);
  angleVelocity = ofVec2f(ofRandom(-0.05, 0.05), ofRandom(-0.05, 0.05));
  amplitude =
      ofVec2f(ofRandom(20, ofGetWidth() * 0.5), ofRandom(ofGetHeight() * 0.5));
}

void Oscillator::update() {
  angle += angleVelocity;

  x = sin(angle.x) * amplitude.x;
  y = sin(angle.y) * amplitude.y;
}

void Oscillator::show() {
  ofPushMatrix();
  ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

  ofSetLineWidth(2);

  ofSetColor(0);
  ofDrawLine(0, 0, x, y);

  ofFill();
  ofSetColor(127);
  ofDrawCircle(x, y, 16);

  ofNoFill();
  ofSetColor(0);
  ofDrawCircle(x, y, 16);

  ofPopMatrix();
}
