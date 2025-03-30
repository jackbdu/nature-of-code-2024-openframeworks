#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  font.load("CourierPrime-Regular.ttf", 12);

  target = "to be or not to be";
  mutationRate = 0.01;
  populationSize = 150;

  for (int i = 0; i < populationSize; ++i) {
    shared_ptr<DNA> phrase = make_shared<DNA>();
    phrase->setup(target.size());
    population.push_back(phrase);
  }
}

//--------------------------------------------------------------
void ofApp::update() {
  ofBackground(255);

  for (auto phrase : population) {
    phrase->calculateFitness(target);
  }

  vector<shared_ptr<DNA>> matingPool;

  for (auto phrase : population) {
    int n = floor(phrase->fitness * 100);
    for (int j = 0; j < n; ++j) {
      matingPool.push_back(phrase);
    }
  }

  for (int i = 0; i < population.size(); ++i) {
    shared_ptr<DNA> partnerA = matingPool[int(ofRandom(matingPool.size()))];
    shared_ptr<DNA> partnerB = matingPool[int(ofRandom(matingPool.size()))];
    shared_ptr<DNA> child = partnerA->crossover(partnerB);
    child->mutate(mutationRate);

    population[i] = child;
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofSetColor(0);
  for (int i = 0; i < population.size() - 2; i += 3) {
    const int y = 12 + 5 * i;
    string line = "";
    line += population[i]->getPhrase() + "    ";
    line += population[i + 1]->getPhrase() + "    ";
    line += population[i + 2]->getPhrase() + "    ";
    font.drawString(line, 12, y);
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
