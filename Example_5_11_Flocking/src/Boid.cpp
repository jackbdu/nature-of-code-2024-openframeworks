#include "Boid.h"

void Boid::setup(float x, float y) {
  position = ofVec2f(x, y);
  velocity = ofVec2f(ofRandom(-1, 1), ofRandom(-1, 1));
  acceleration = ofVec2f(0, 0);
  r = 3;
  maxSpeed = 3;
  maxForce = 0.05;
}

void Boid::applyForce(ofVec2f force) { acceleration += force; }

void Boid::flock(vector<Boid *> boids) {
  ofVec2f sep = separate(boids);
  ofVec2f ali = align(boids);
  ofVec2f coh = cohere(boids);

  sep *= 1.5;
  ali *= 1.0;
  coh *= 1.0;

  applyForce(sep);
  applyForce(ali);
  applyForce(coh);
}

void Boid::update(vector<Boid *> boids) {
  flock(boids);

  velocity += acceleration;
  velocity.limit(maxSpeed);
  position += velocity;
  acceleration *= 0;

  borders();
}

void Boid::show() {
  const float angle = ofVec2f(1, 0).angleRad(velocity);

  ofPushMatrix();

  ofTranslate(position.x, position.y);
  ofRotateRad(angle);

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
}

void Boid::borders() {
  if (position.x < -r)
    position.x = ofGetWidth() + r;
  if (position.y < -r)
    position.y = ofGetHeight() + r;
  if (position.x > ofGetWidth() + r)
    position.x = -r;
  if (position.y > ofGetHeight() + r)
    position.y = -r;
}

ofVec2f Boid::seek(ofVec2f target) {
  ofVec2f desired = target - position;
  desired.scale(maxSpeed);

  ofVec2f steer = desired - velocity;
  steer.limit(maxForce);

  return steer;
}

ofVec2f Boid::separate(vector<Boid *> boids) {
  const float desiredSeparation = 25;
  ofVec2f steer;

  for (auto other : boids) {
    const float d = position.distance(other->position);
    if (this != other && d < desiredSeparation) {
      ofVec2f diff = position - other->position;
      diff.normalize();
      diff /= d;
      steer += diff;
    }
  }

  if (steer.length() > 0) {
    steer.scale(maxSpeed);
    steer -= velocity;
    steer.limit(maxForce);
  }

  return steer;
}

ofVec2f Boid::align(vector<Boid *> boids) {
  const float neighborDistance = 50;
  ofVec2f steer;
  int count = 0;

  for (auto other : boids) {
    const float d = position.distance(other->position);
    if (this != other && d < neighborDistance) {
      steer += other->velocity;
      ++count;
    }
  }

  if (count > 0) {
    steer.scale(maxSpeed);
    steer -= velocity;
    steer.limit(maxForce);
  }

  return steer;
}

ofVec2f Boid::cohere(vector<Boid *> boids) {
  const float neighborDistance = 50;
  ofVec2f sum;
  int count = 0;

  for (auto other : boids) {
    const float d = position.distance(other->position);
    if (this != other && d < neighborDistance) {
      sum += other->position;
      ++count;
    }
  }

  if (count > 0) {
    sum /= count;
    return seek(sum);
  } else {
    return ofVec2f(0, 0);
  }
}
