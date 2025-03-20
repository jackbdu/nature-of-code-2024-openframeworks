#pragma once

#include "ofMain.h"

class MyPoint {
public:
  float x;
  float y;
  void setup(float _x, float _y) {
    x = _x;
    y = _y;
  }
};

class Rectangle {
public:
  float x;
  float y;
  float w;
  float h;
  void setup(float _x, float _y, float _w, float _h) {
    x = _x;
    y = _y;
    w = _w;
    h = _h;
  }

  bool contains(MyPoint point) {
    return (point.x >= x - w && point.x < x + w && point.y >= y - h &&
            point.y < y + h);
  }

  bool intersects(Rectangle range) {
    return !(range.x - range.w > x + w || range.x + range.w < x - w ||
             range.y - range.h > y + h || range.y + range.h < y - h);
  }
};

class QuadTree {
public:
  void setup(Rectangle _boundary, int n);
  void subdivide();
  bool insert(MyPoint point);
  vector<MyPoint> query(Rectangle range,
                        vector<MyPoint> *found = new vector<MyPoint>());
  void show();

  Rectangle boundary;
  int capacity;
  vector<MyPoint> points;
  bool divided;
  QuadTree *northeast;
  QuadTree *northwest;
  QuadTree *southeast;
  QuadTree *southwest;
};
