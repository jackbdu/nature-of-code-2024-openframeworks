#include "LSystem.h"

void LSystem::setup(string axiom, map<string, string> rules) {
  sentence = axiom;
  ruleset = rules;
};

void LSystem::generate() {
  string nextgen = "";
  for (int i = 0; i < sentence.size(); ++i) {
    string c = ofToString(sentence[i]);
    if (ruleset.find(c) != ruleset.end()) {
      nextgen += ruleset[c];
    } else {
      nextgen += c;
    }
  }

  sentence = nextgen;
};
