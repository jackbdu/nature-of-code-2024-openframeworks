#include "Rocket.h"

void Rocket::setup(float x, float y, shared_ptr<DNA> _dna) {
  position = ofVec2f(x, y);
  r = 4;
  fitness = 0;
  dna = _dna;
  geneCounter = 0;
}

void Rocket::calculateFitness(ofVec2f target) {
  const float distance = position.distance(target);
  fitness = 1 / (distance * distance);
}

void Rocket::applyForce(ofVec2f force) { acceleration += force; }

void Rocket::run() {
  applyForce(dna->genes[geneCounter]);
  geneCounter += 1;

  update();
}

void Rocket::update() {
  velocity += acceleration;
  position += velocity;
  acceleration *= 0;
}

void Rocket::show() {
  const float angle = ofVec2f(1, 0).angleRad(velocity) + HALF_PI;

  ofSetLineWidth(1);

  ofPushMatrix();

  ofTranslate(position.x, position.y);
  ofRotateRad(angle);

  ofSetRectMode(OF_RECTMODE_CENTER);

  ofSetColor(0);
  ofFill();
  ofDrawRectangle(-r * 0.5, r * 2, r * 0.5, r);
  ofDrawRectangle(r * 0.5, r * 2, r * 0.5, r);

  ofSetColor(0);
  ofNoFill();
  ofDrawRectangle(-r * 0.5, r * 2, r * 0.5, r);
  ofDrawRectangle(r * 0.5, r * 2, r * 0.5, r);

  ofSetColor(200);
  ofFill();
  ofDrawTriangle(0, -r * 2, -r, r * 2, r, r * 2);

  ofSetColor(0);
  ofNoFill();
  ofDrawTriangle(0, -r * 2, -r, r * 2, r, r * 2);

  ofPopMatrix();
}
