#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  font.load("CourierPrime-Regular.ttf", 12);

  lifeSpan = 250;
  lifeCounter = 0;

  target = ofVec2f(ofGetWidth() * 0.5, 24);
  mutationRate = 0.01;

  population.setup(mutationRate, 50, lifeSpan);
}

//--------------------------------------------------------------
void ofApp::update() {
  ofBackground(255);
  if (lifeCounter < lifeSpan) {
    population.live();
    ++lifeCounter;
  } else {
    lifeCounter = 0;
    population.fitness(target);
    population.selection();
    population.reproduction();
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofSetColor(127);
  ofFill();
  ofDrawCircle(target.x, target.y, 12);

  ofSetColor(0);
  ofNoFill();
  ofSetLineWidth(2);
  ofDrawCircle(target.x, target.y, 12);

  population.show();

  ofSetColor(0);
  font.drawString("Generation #: " + ofToString(population.generations) +
                      "\nCycles left: " + ofToString(lifeSpan - lifeCounter),
                  10, 20);
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
void ofApp::mousePressed(int x, int y, int button) {
  target.x = x;
  target.y = y;
}

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
