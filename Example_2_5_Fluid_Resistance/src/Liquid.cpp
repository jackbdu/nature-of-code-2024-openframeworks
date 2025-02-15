#include "Liquid.h"

void Liquid::setup(float _x, float _y, float _w, float _h, float _c) {
  x = _x;
  y = _y;
  w = _w;
  h = _h;
  c = _c;
}

bool Liquid::contains(Mover mover) {
  const ofVec2f pos = mover.position;
  return (pos.x > x && pos.x < x + w && pos.y > y && pos.y < y + h);
}

ofVec2f Liquid::calculateDrag(Mover mover) {
  const float speed = mover.velocity.length();
  const float dragMagnitude = c * speed * speed;

  ofVec2f dragForce = mover.velocity;
  dragForce *= -1;

  dragForce.scale(dragMagnitude);

  return dragForce;
}

void Liquid::show() {
  ofFill();
  ofSetColor(220);
  ofDrawRectangle(x, y, w, h);
}
