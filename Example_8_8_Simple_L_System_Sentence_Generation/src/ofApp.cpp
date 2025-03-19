#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() { font.load("CourierPrime-Regular.ttf", 12); }

//--------------------------------------------------------------
void ofApp::update() { ofBackground(255); }

//--------------------------------------------------------------
void ofApp::draw() {
  current = "A";
  for (int i = 0; i < 9; ++i) {
    generate();
    ofSetColor(0);
    string text = ofToString(i) + ": " + current;
    font.drawString(text, 4, 20 + i * 16);
  }
}

//--------------------------------------------------------------
void ofApp::generate() {
  string next = "";
  for (int i = 0; i < current.size(); ++i) {
    char c = current[i];
    if (c == 'A') {
      next += "AB";
    } else if (c == 'B') {
      next += "A";
    }
  }

  current = next;
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
