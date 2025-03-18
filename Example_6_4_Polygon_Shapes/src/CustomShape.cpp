#include "CustomShape.h"

void CustomShape::setup(ofxBox2d *box2d, float x, float y) {
  polyline.addVertex(-10, -10);
  polyline.addVertex(20, -15);
  polyline.addVertex(15, 0);
  polyline.addVertex(0, 10);
  polyline.addVertex(-20, 15);
  polyline.close();

  ofPolyline translatedPolyline = polyline;
  translatedPolyline.translate(ofVec2f(x, y));

  shape = make_shared<ofxBox2dPolygon>();
  shape->addVertices(translatedPolyline.getVertices());

  shape->setDensity(1);
  shape->setFriction(0.2);
  shape->setBounce(0.2);
  shape->create(box2d->getWorld());
  shape->setVelocity(ofRandom(-5, 5), 0);
  shape->body->SetAngularVelocity(2.5);
};

void CustomShape::show() {

  auto vertices = shape->getPoints();
  ofVec2f pos = shape->getPosition();
  float angle = shape->getRotation();

  ofSetRectMode(OF_RECTMODE_CENTER);
  ofSetLineWidth(2);

  ofPushMatrix();

  ofTranslate(pos.x, pos.y);
  ofRotate(angle);

  ofFill();
  ofSetColor(127);
  ofBeginShape();
  for (auto &vertex : polyline.getVertices()) {
    ofVertex(vertex);
  }
  ofEndShape(true);

  ofNoFill();
  ofSetColor(0);
  polyline.draw();

  ofPopMatrix();
};

bool CustomShape::checkEdge() {
  return shape->getPosition().y > ofGetHeight() + 100;
}

void CustomShape::removeBody() { shape->clear(); }
