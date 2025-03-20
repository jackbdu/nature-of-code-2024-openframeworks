#pragma once

#include "ofMain.h"

class LSystem {
public:
  void setup(string axiom, map<string, string> rules);
  void generate();

  string sentence;
  map<string, string> ruleset;
};
