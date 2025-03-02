#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  debug = true;
  flowfield.setup(20);

  for (int i = 0; i < 120; ++i) {
    Vehicle vehicle;
    vehicle.setup(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()),
                  ofRandom(2, 5), ofRandom(0.1, 0.5));
    vehicles.push_back(vehicle);
  }
}

//--------------------------------------------------------------
void ofApp::update() {
  ofBackground(255);

  for (int i = 0; i < vehicles.size(); ++i) {
    vehicles[i].follow(flowfield);
    vehicles[i].update();
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  if (debug)
    flowfield.show();

  for (int i = 0; i < vehicles.size(); ++i) {
    vehicles[i].show();
  }
}

//--------------------------------------------------------------
void ofApp::exit() {}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  if (key == ' ')
    debug = !debug;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) { flowfield.init(); }

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
