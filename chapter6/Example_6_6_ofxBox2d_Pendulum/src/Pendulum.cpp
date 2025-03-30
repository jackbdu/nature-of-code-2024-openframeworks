#include "Pendulum.h"

void Pendulum::setup(ofxBox2d *box2d, float x, float y, float _len) {
  r = 12;
  len = _len;

  anchor = make_shared<ofxBox2dCircle>();
  anchor->setup(box2d->getWorld(), x, y, r);

  bob = make_shared<ofxBox2dCircle>();
  bob->setDensity(1);
  bob->setBounce(0.6);
  bob->setup(box2d->getWorld(), x + len, y - len, r);

  arm = make_shared<ofxBox2dJoint>();
  arm->setup(box2d->getWorld(), anchor->body, bob->body);
  arm->setLength(len);
}

void Pendulum::show() {
  ofVec2f anchorPos = anchor->getPosition();
  ofVec2f bobPos = bob->getPosition();
  float anchorAngle = anchor->getRotation();
  float bobAngle = anchor->getRotation();

  ofSetLineWidth(2);

  ofSetColor(0);
  ofNoFill();

  ofDrawLine(anchorPos.x, anchorPos.y, bobPos.x, bobPos.y);

  ofPushMatrix();

  ofTranslate(anchorPos.x, anchorPos.y);
  ofRotate(anchorAngle);

  ofFill();
  ofSetColor(127);
  ofDrawCircle(0, 0, r);

  ofNoFill();
  ofSetColor(0);
  ofDrawCircle(0, 0, r);
  ofDrawLine(0, 0, r, 0);

  ofPopMatrix();

  ofPushMatrix();

  ofTranslate(bobPos.x, bobPos.y);
  ofRotate(bobAngle);

  ofFill();
  ofSetColor(127);
  ofDrawCircle(0, 0, r);

  ofNoFill();
  ofSetColor(0);
  ofDrawCircle(0, 0, r);
  ofDrawLine(0, 0, r, 0);

  ofPopMatrix();
}
