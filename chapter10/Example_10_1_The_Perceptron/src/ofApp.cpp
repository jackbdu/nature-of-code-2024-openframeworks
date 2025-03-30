#include "ofApp.h"

float ofApp::f(float x) { return 0.5 * x + 1; }

//--------------------------------------------------------------
void ofApp::setup() {
  count = 0;
  perceptron.setup(3, 0.0001);

  for (int i = 0; i < 2000; ++i) {
    const float x = ofRandom(-ofGetWidth() * 0.5, ofGetWidth() * 0.5);
    const float y = ofRandom(-ofGetHeight() * 0.5, ofGetHeight() * 0.5);
    training.push_back({x, y, 1});
  }
}

//--------------------------------------------------------------
void ofApp::update() {
  ofBackground(255);

  float x = training[count][0];
  float y = training[count][1];
  int desired = -1;
  if (y > f(x)) {
    desired = 1;
  }

  perceptron.train(training[count], desired);

  count = (count + 1) % training.size();
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
  ofScale(1, -1);

  ofSetLineWidth(2);
  ofSetColor(0);
  ofDrawLine(-ofGetWidth() * 0.5, f(-ofGetWidth() * 0.5), ofGetWidth() * 0.5,
             f(ofGetWidth() * 0.5));

  for (auto dataPoint : training) {
    const float guess = perceptron.feedforward(dataPoint);

    if (guess > 0) {
      ofSetColor(127);
    } else {
      ofSetColor(255);
    }
    ofFill();
    ofDrawCircle(dataPoint[0], dataPoint[1], 4);

    ofSetLineWidth(1);
    ofSetColor(0);
    ofNoFill();
    ofDrawCircle(dataPoint[0], dataPoint[1], 4);
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
