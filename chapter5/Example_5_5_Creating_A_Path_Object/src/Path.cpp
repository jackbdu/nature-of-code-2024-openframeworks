#include "Path.h"

void Path::setup() {
  radius = 20;
  start = ofVec2f(0, ofGetHeight() / 3.0);
  end = ofVec2f(ofGetWidth(), ofGetHeight() * 2.0 / 3.0);
}

void Path::show() {
  ofSetColor(150);
  drawThickLine(start, end, radius * 2);

  ofSetLineWidth(1);
  ofSetColor(0);
  ofDrawLine(start.x, start.y, end.x, end.y);
}

void Path::drawThickLine(ofVec2f start, ofVec2f end, float lineWidth) {
  const ofVec2f line = end - start;
  const float length = line.length();
  const float angle = ofVec2f(1, 0).angleRad(line);
  const ofVec2f center = (start + end) * 0.5;

  ofDrawCircle(start.x, start.y, lineWidth * 0.5);
  ofDrawCircle(end.x, end.y, lineWidth * 0.5);

  ofPushMatrix();

  ofTranslate(center.x, center.y);
  ofRotateRad(angle);

  ofSetRectMode(OF_RECTMODE_CENTER);
  ofDrawRectangle(0, 0, length, lineWidth);

  ofPopMatrix();
}
