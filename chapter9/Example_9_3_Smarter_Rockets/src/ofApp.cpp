#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  font.load("CourierPrime-Regular.ttf", 12);

  lifeSpan = 250;
  lifeCounter = 0;
  recordTime = lifeSpan;

  target.setup(ofGetWidth() * 0.5 - 12, 24, 24, 24);

  population.setup(0.01, 150, lifeSpan);

  Obstacle obstacle;
  obstacle.setup(ofGetWidth() * 0.5 - 75, ofGetHeight() * 0.5, 150, 10);
  obstacles.push_back(obstacle);
}

//--------------------------------------------------------------
void ofApp::update() {
  ofBackground(255);
  if (lifeCounter < lifeSpan) {
    population.live(obstacles, target);
    if (population.targetReached() && lifeCounter < recordTime) {
      recordTime = lifeCounter;
    } else {
      ++lifeCounter;
    }
  } else {
    lifeCounter = 0;
    population.checkFitness();
    population.selection();
    population.reproduction();
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  target.show();

  population.show();

  for (int i = 0; i < obstacles.size(); ++i) {
    obstacles[i].show();
  }

  ofSetColor(0);
  font.drawString("Generation #: " + ofToString(population.generations), 10,
                  18);
  font.drawString("Cycles left: " + ofToString(lifeSpan - lifeCounter), 10, 36);
  font.drawString("Record cycles: " + ofToString(recordTime), 10, 54);
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
  target.position.x = x;
  target.position.y = y;
  recordTime = lifeSpan;
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
