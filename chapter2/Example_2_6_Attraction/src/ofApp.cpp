#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  mover.setup(300, 50, 2);
  attractor.setup();
}

//--------------------------------------------------------------
void ofApp::update() {
  const ofVec2f force = attractor.attract(mover);
  mover.applyForce(force);
  mover.update();

  ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::draw() {
  attractor.show();
  mover.show();
}

//--------------------------------------------------------------
void ofApp::exit() {}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) { attractor.handleHover(x, y); }

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

  attractor.handleHover(x, y);
  attractor.handleDrag(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

  attractor.handlePress(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
  attractor.stopDragging();
}

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
