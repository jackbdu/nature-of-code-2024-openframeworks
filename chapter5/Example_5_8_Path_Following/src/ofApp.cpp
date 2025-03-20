#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  debug = true;

  newPath();

  car1.setup(0, ofGetHeight() * 0.5, 2, 0.04);
  car2.setup(0, ofGetHeight() * 0.5, 3, 0.1);
}

//--------------------------------------------------------------
void ofApp::update() {
  ofBackground(255);

  car1.borders(path);
  car2.borders(path);

  car1.follow(path);
  car2.follow(path);

  car1.update();
  car2.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
  path.show();
  car1.show(path, debug);
  car2.show(path, debug);
}

//--------------------------------------------------------------
void ofApp::newPath() {
  path.setup();
  path.addPoint(-20, ofGetHeight() * 0.5);
  path.addPoint(ofRandom(0, ofGetWidth() * 0.5), ofRandom(0, ofGetHeight()));
  path.addPoint(ofRandom(ofGetWidth() * 0.5, ofGetWidth()),
                ofRandom(0, ofGetHeight()));
  path.addPoint(ofGetWidth() + 20, ofGetHeight() * 0.5);
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
void ofApp::mousePressed(int x, int y, int button) { newPath(); }

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
