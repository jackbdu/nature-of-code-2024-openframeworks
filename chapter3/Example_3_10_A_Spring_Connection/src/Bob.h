#ifndef _BOB
#define _BOB

#include "ofMain.h"

class Bob {
public:
  void setup(float x, float y);
  void update();
  void show();
  void applyForce(ofVec2f force);
  void handleClick(float mx, float my);
  void handleDrag(float mx, float my);
  void stopDragging();

  ofVec2f position;
  ofVec2f velocity;
  ofVec2f acceleration;
  ofVec2f dragOffset;
  bool dragging;
  float mass;
  float damping;
};

#endif
