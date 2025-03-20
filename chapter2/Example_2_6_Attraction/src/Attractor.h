#ifndef _ATTRACTOR
#define _ATTRACTOR

#include "Mover.h"
#include "ofMain.h"

class Attractor {
public:
  void setup();
  void show();
  void handlePress(float mx, float my);
  void handleHover(float mx, float my);
  void handleDrag(float mx, float my);
  void stopDragging();
  ofVec2f attract(Mover mover);

  float G;
  float mass;
  ofVec2f position;
  ofVec2f dragOffset;
  bool dragging;
  bool rollover;
};

#endif
