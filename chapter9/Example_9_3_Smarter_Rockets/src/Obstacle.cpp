#include "Obstacle.h"

void Obstacle::setup(float x, float y, float width, float height) {
  position = ofVec2f(x, y);
  w = width;
  h = height;
};

void Obstacle::show() {
  ofSetLineWidth(2);
  ofSetRectMode(OF_RECTMODE_CORNER);

  ofSetColor(175);
  ofFill();
  ofDrawRectangle(position.x, position.y, w, h);

  ofSetColor(0);
  ofNoFill();
  ofDrawRectangle(position.x, position.y, w, h);
};

bool Obstacle::contains(ofVec2f spot) {
  return (spot.x > position.x && spot.x < position.x + w &&
          spot.y > position.y && spot.y < position.y + h);
};
