#include "QuadTree.h"

void QuadTree::setup(Rectangle _boundary, int n) {
  boundary = _boundary;
  capacity = n;
  divided = false;
};

void QuadTree::subdivide() {
  const float x = boundary.x;
  const float y = boundary.y;
  const float w = boundary.w;
  const float h = boundary.h;

  Rectangle ne, nw, se, sw;
  ne.setup(x + w * 0.5, y - h * 0.5, w * 0.5, h * 0.5);
  nw.setup(x - w * 0.5, y - h * 0.5, w * 0.5, h * 0.5);
  se.setup(x + w * 0.5, y + h * 0.5, w * 0.5, h * 0.5);
  sw.setup(x - w * 0.5, y + h * 0.5, w * 0.5, h * 0.5);

  northeast = new QuadTree();
  northwest = new QuadTree();
  southeast = new QuadTree();
  southwest = new QuadTree();
  northeast->setup(ne, capacity);
  northwest->setup(nw, capacity);
  southeast->setup(se, capacity);
  southwest->setup(sw, capacity);

  divided = true;
};

bool QuadTree::insert(MyPoint point) {
  if (!boundary.contains(point)) {
    return false;
  }

  if (points.size() < capacity) {
    points.push_back(point);
    return true;
  } else {
    if (!divided) {
      subdivide();
    }
    if (northeast->insert(point)) {
      return true;
    } else if (northwest->insert(point)) {
      return true;
    } else if (southeast->insert(point)) {
      return true;
    } else if (southwest->insert(point)) {
      return true;
    }
  }
  return false;
};

vector<MyPoint> QuadTree::query(Rectangle range, vector<MyPoint> *found) {
  if (boundary.intersects(range)) {
    for (auto p : points) {
      if (range.contains(p)) {
        found->push_back(p);
      }
    }
    if (divided) {
      northwest->query(range, found);
      northeast->query(range, found);
      southwest->query(range, found);
      southeast->query(range, found);
    }
  }
  return *found;
};

void QuadTree::show() {
  ofSetLineWidth(1);
  ofSetColor(0);
  ofNoFill();
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofDrawRectangle(boundary.x, boundary.y, boundary.w * 2, boundary.h * 2);

  ofSetColor(0);
  ofFill();
  for (auto p : points) {
    ofDrawCircle(p.x, p.y, 0.5);
  }

  if (divided) {
    northwest->show();
    northeast->show();
    southwest->show();
    southeast->show();
  }
};
