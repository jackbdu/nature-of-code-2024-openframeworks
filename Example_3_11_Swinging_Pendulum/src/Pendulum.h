#ifndef _PENDULUM
#define _PENDULUM

#include "ofMain.h"

class Pendulum {
public:
  void setup(float x, float y, float r);
  void update();
  void show();
  void clicked(float mx, float my);
  void drag(float mx, float my);
  void stopDragging();

  ofVec2f pivot;
  ofVec2f bob;
  float angle;
  float radius;
  bool dragging;
  float angleVelocity = 0;
  float angleAcceleration = 0;
  float damping;
  float ballRadius;
};

#endif
