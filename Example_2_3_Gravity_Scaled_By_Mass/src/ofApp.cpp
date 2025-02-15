#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  moverA.setup(200, 30, 10);
  moverB.setup(440, 30, 2);
}

//--------------------------------------------------------------
void ofApp::update() {
  const ofVec2f gravity = ofVec2f(0, 0.1);
  moverA.applyForce(gravity);
  moverB.applyForce(gravity);

  if (ofGetMousePressed()) {
    const ofVec2f wind = ofVec2f(0.1, 0);
    moverA.applyForce(wind);
    moverB.applyForce(wind);
  }

  moverA.update();
  moverA.checkEdges();

  moverB.update();
  moverB.checkEdges();

  ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::draw() {
  moverA.show();
  moverB.show();
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
