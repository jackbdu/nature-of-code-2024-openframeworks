#include "Path.h"

void Path::setup() {
  radius = 20;
  points.clear();
}

void Path::addPoint(float x, float y) {
  const ofVec2f point = ofVec2f(x, y);
  points.push_back(point);
}

ofVec2f Path::getStart() { return points.front(); }

ofVec2f Path::getEnd() { return points.back(); }

void Path::show() {
  ofSetColor(200);
  ofFill();
  for (int i = 0; i < points.size(); ++i) {
    auto start = points[i - 1];
    auto end = points[i];
    drawThickLine(start, end, radius * 2);
  }

  ofSetLineWidth(1);
  ofNoFill();
  ofSetColor(0);
  ofBeginShape();
  for (auto pathPoint : points) {
    ofVertex(pathPoint.x, pathPoint.y);
  }
  ofEndShape();
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
