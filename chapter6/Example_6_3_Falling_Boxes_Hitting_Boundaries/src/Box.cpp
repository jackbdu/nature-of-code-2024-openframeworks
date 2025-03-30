#include "Box.h"

void Box::setup(ofxBox2d *box2d, float x, float y) {
  w = ofRandom(8, 16);
  h = ofRandom(8, 16);

  shape = make_shared<ofxBox2dRect>();
  shape->setDensity(1);
  shape->setFriction(0.2);
  shape->setBounce(0.6);
  shape->setup(box2d->getWorld(), x, y, w, h);
  shape->setVelocity(ofRandom(-5, 5), 0);
  shape->body->SetAngularVelocity(2.5);
}

void Box::show() {
  ofVec2f pos = shape->getPosition();
  float angle = shape->getRotation();

  ofSetRectMode(OF_RECTMODE_CENTER);
  ofSetLineWidth(2);

  ofPushMatrix();

  ofTranslate(pos.x, pos.y);
  ofRotate(angle);

  ofFill();
  ofSetColor(127);
  ofDrawRectangle(0, 0, w, h);

  ofNoFill();
  ofSetColor(0);
  ofDrawRectangle(0, 0, w, h);

  ofPopMatrix();
}

bool Box::checkEdge() { return shape->getPosition().y > ofGetHeight() + w; }

void Box::removeBody() { shape->destroy(); }
