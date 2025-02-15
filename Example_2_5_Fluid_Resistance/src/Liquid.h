#ifndef _LIQUID
#define _LIQUID

#include "Mover.h"
#include "ofMain.h"

class Liquid {
public:
  void setup(float _x, float _y, float _w, float _h, float _c);
  void show();
  bool contains(Mover mover);
  ofVec2f calculateDrag(Mover mover);

  float x;
  float y;
  float w;
  float h;
  float c;
};

#endif
