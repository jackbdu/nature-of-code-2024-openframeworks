#include "Rocket.h"

void Rocket::setup(float x, float y, shared_ptr<DNA> _dna) {
  position = ofVec2f(x, y);
  dna = _dna;
  r = 4;
  finishCounter = 0;
  recordDistance = 99999;
  fitness = 0;
  geneCounter = 0;
  hitObstacle = false;
  hitTarget = false;
}

void Rocket::calculateFitness() {
  fitness = 1 / (finishCounter * recordDistance);
  fitness = pow(fitness, 4);

  if (hitObstacle)
    fitness *= 0.1;

  if (hitTarget)
    fitness *= 2;
}

void Rocket::run(vector<Obstacle> obstacles) {
  if (!hitObstacle && !hitTarget) {
    applyForce(dna->genes[geneCounter]);
    geneCounter = (geneCounter + 1) % dna->genes.size();
    update();
    checkObstacles(obstacles);
  }
};

void Rocket::checkTarget(Obstacle target) {
  const float distance = position.distance(target.position);

  if (distance < recordDistance)
    recordDistance = distance;

  if (target.contains(position))
    hitTarget = true;

  if (!hitTarget)
    ++finishCounter;
}

void Rocket::checkObstacles(vector<Obstacle> obstacles) {
  for (int i = 0; i < obstacles.size(); ++i) {
    if (obstacles[i].contains(position))
      hitObstacle = true;
  }
};

void Rocket::applyForce(ofVec2f force) { acceleration += force; }

void Rocket::update() {
  velocity += acceleration;
  position += velocity;
  acceleration *= 0;
}

void Rocket::show() {
  const float theta = ofVec2f(1, 0).angleRad(velocity) + HALF_PI;

  ofSetLineWidth(1);

  ofPushMatrix();

  ofTranslate(position.x, position.y);
  ofRotateRad(theta);

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
