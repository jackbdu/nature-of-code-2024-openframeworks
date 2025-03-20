#include "Vehicle.h"

void Vehicle::setup(float x, float y, float _maxSpeed, float _maxForce) {
  position = ofVec2f(x, y);
  velocity = ofVec2f(2, 0);
  acceleration = ofVec2f(0, 0);
  r = 4;
  maxSpeed = _maxSpeed;
  maxForce = _maxForce;
}

void Vehicle::follow(Path path) {
  future = velocity;
  future.scale(50);
  future += position;

  hasTarget = false;
  worldRecord = 99999; // alternative?

  for (int i = 0; i < path.points.size() - 1; ++i) {
    ofVec2f a = path.points[i];
    ofVec2f b = path.points[i + 1];

    ofVec2f normalPoint = getNormalPoint(future, a, b);
    if (normalPoint.x < a.x || normalPoint.x > b.x) {
      normalPoint = b;
    }

    const float distance = normalPoint.distance(future);

    if (distance < worldRecord) {
      worldRecord = distance;
      normal = normalPoint;
      target = normalPoint;
      hasTarget = true;

      ofVec2f dir = b - a;
      dir.scale(10);
      target += dir;
    }
  }

  if (worldRecord > path.radius && hasTarget) {
    seek(target);
  }
}

void Vehicle::applyForce(ofVec2f force) { acceleration += force; }

void Vehicle::seek(ofVec2f target) {
  ofVec2f desired = target - position;

  if (desired.length() == 0)
    return;

  desired.scale(maxSpeed);

  ofVec2f steer = desired - velocity;
  steer.limit(maxForce);

  applyForce(steer);
}

void Vehicle::update() {
  velocity += acceleration;
  velocity.limit(maxSpeed);
  position += velocity;

  acceleration *= 0;
}

void Vehicle::borders(Path path) {
  if (position.x > path.getEnd().x + r) {
    position.x = path.getStart().x - r;
    position.y = path.getStart().y + (position.y - path.getEnd().y);
  }
}

void Vehicle::show(Path path, bool debug) {
  const float theta = ofVec2f(1, 0).angleRad(velocity);

  ofPushMatrix();

  ofTranslate(position.x, position.y);
  ofRotateRad(theta);

  ofSetLineWidth(2);

  ofFill();
  ofSetColor(127);
  ofBeginShape();
  ofVertex(r * 2, 0);
  ofVertex(-r * 2, -r);
  ofVertex(-r * 2, r);
  ofEndShape(true);

  ofNoFill();
  ofSetColor(0);
  ofBeginShape();
  ofVertex(r * 2, 0);
  ofVertex(-r * 2, -r);
  ofVertex(-r * 2, r);
  ofEndShape(true);

  ofPopMatrix();

  if (debug) {
    ofSetColor(0);
    ofNoFill();
    ofDrawLine(position.x, position.y, future.x, future.y);
    ofDrawLine(future.x, future.y, normal.x, normal.y);

    ofSetColor(127);
    ofFill();
    ofDrawCircle(future.x, future.y, 2);
    ofDrawCircle(normal.x, normal.y, 2);

    ofSetColor(0);
    ofNoFill();
    ofDrawCircle(future.x, future.y, 2);
    ofDrawCircle(normal.x, normal.y, 2);

    ofSetColor(127);
    ofFill();
    if (worldRecord > path.radius)
      ofSetColor(255, 0, 0);
    ofDrawCircle(target.x, target.y, 4);
  }
}

ofVec2f Vehicle::getNormalPoint(ofVec2f p, ofVec2f a, ofVec2f b) {
  const ofVec2f ap = p - a;
  ofVec2f ab = b - a;

  ab.normalize();
  ab *= ap.dot(ab);

  const ofVec2f normalPoint = a + ab;

  return normalPoint;
}
