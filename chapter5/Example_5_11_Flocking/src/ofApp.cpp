#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  flock.setup();
  for (int i = 0; i < 120; ++i) {
    Boid *boid = new Boid();
    boid->setup(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
    flock.addBoid(boid);
  }
}

//--------------------------------------------------------------
void ofApp::update() {
  ofBackground(255);
  flock.update();
}

//--------------------------------------------------------------
void ofApp::draw() { flock.show(); }

//--------------------------------------------------------------
void ofApp::exit() {}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
  Boid *boid = new Boid();
  boid->setup(x, y);
  flock.addBoid(boid);
}

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
