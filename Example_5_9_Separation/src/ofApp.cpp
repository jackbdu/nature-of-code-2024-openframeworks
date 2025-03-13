#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  for (int i = 0; i < 25; ++i) {
    Vehicle *vehicle = new Vehicle();
    vehicle->setup(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    vehicles.push_back(vehicle);
  }
}

//--------------------------------------------------------------
void ofApp::update() {
  ofBackground(255);

  for (auto v : vehicles) {
    v->separate(vehicles);
    v->update();
    v->borders();
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  for (auto v : vehicles) {
    v->show();
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
void ofApp::mouseDragged(int x, int y, int button) {
  Vehicle *vehicle = new Vehicle();
  vehicle->setup(x, y);
  vehicles.push_back(vehicle);
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
