#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  SC_PRECISION = 0.5;
  SC_INV_PREC = 1 / SC_PRECISION;
  SC_PERIOD = floor(360 * SC_INV_PREC);

  initSinCos();
}

//--------------------------------------------------------------
void ofApp::update() {
  ofBackground(255);
  radius = 50 + 50 * sinLUT[ofGetFrameNum() % SC_PERIOD];
}

//--------------------------------------------------------------
void ofApp::draw() {
  for (int i = 0; i < 360; i += 5) {
    const int theta = int(i * SC_INV_PREC) % SC_PERIOD;
    const float x = ofGetWidth() * 0.5 + radius * cosLUT[theta];
    const float y = ofGetHeight() * 0.5 + radius * sinLUT[theta];
    const float r = 2;
    ofSetColor(0);
    ofFill();
    ofDrawCircle(x, y, r);
  }
}

//--------------------------------------------------------------
void ofApp::initSinCos() {
  for (int i = 0; i < SC_PERIOD; ++i) {
    sinLUT.push_back(sin(i * DEG_TO_RAD * SC_PRECISION));
    cosLUT.push_back(cos(i * DEG_TO_RAD * SC_PRECISION));
  }
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
