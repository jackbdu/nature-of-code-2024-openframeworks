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
  future.scale(25);
  future += position;

  normalPoint = getNormalPoint(future, path.start, path.end);

  targetVector = path.end - path.start;
  targetVector.scale(25);
  target = normalPoint + targetVector;

  distance = normalPoint.distance(future);
  if (distance > path.radius) {
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
  if (position.x > path.end.x + r) {
    position.x = path.start.x - r;
    position.y = path.start.y + (position.y - path.end.y);
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
    ofDrawLine(future.x, future.y, normalPoint.x, normalPoint.y);

    ofSetColor(127);
    ofFill();
    ofDrawCircle(future.x, future.y, 2);
    ofDrawCircle(normalPoint.x, normalPoint.y, 2);

    ofSetColor(0);
    ofNoFill();
    ofDrawCircle(future.x, future.y, 2);
    ofDrawCircle(normalPoint.x, normalPoint.y, 2);

    ofSetColor(127);
    ofFill();
    if (distance > path.radius)
      ofSetColor(255, 0, 0);
    ofDrawCircle(target.x + targetVector.x, target.y + targetVector.y, 4);
  }
}

ofVec2f Vehicle::getNormalPoint(ofVec2f position, ofVec2f a, ofVec2f b) {
  const ofVec2f vectorA = position - a;
  ofVec2f vectorB = b - a;

  vectorB.normalize();
  vectorB *= vectorA.dot(vectorB);

  const ofVec2f normalPoint = a + vectorB;

  return normalPoint;
}
