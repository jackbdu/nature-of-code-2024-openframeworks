#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofBackground(255);

  box2d.init();
  box2d.setGravity(0, 10);
  box2d.createGround();

  box.setDensity(1);
  box.setFriction(0.1);
  box.setBounce(0.75);
  box.setup(box2d.getWorld(), 100, 100, 50, 50);
  box.setVelocity(5, 0);
  // https://box2d.org/doc_version_2_4/classb2_body.html#a1a8ff152b3a0189b391c9dd6b4c5f12c
  box.body->SetAngularVelocity(0.1);
}

//--------------------------------------------------------------
void ofApp::update() { box2d.update(); }

//--------------------------------------------------------------
void ofApp::draw() {
  ofSetColor(127);
  box.draw();
}

//--------------------------------------------------------------
void ofApp::exit() {}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
