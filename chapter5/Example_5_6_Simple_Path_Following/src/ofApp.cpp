#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  debug = true;

  path.setup();

  vehicle1.setup(0, ofGetHeight() * 0.5, 2, 0.02);
  vehicle2.setup(0, ofGetHeight() * 0.5, 3, 0.05);
}

//--------------------------------------------------------------
void ofApp::update() {
  ofBackground(255);

  vehicle1.borders(path);
  vehicle2.borders(path);

  vehicle1.follow(path);
  vehicle2.follow(path);

  vehicle1.update();
  vehicle2.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
  path.show();
  vehicle1.show(path, debug);
  vehicle2.show(path, debug);
}

//--------------------------------------------------------------
void ofApp::exit() {}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  if (key == ' ') {
    debug = !debug;
  }
}

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
