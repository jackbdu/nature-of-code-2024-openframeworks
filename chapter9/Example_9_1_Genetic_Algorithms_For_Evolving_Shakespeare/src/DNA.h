#pragma once

#include "ofMain.h"

class DNA {
public:
  void setup(int length);
  string getPhrase();
  void calculateFitness(string target);
  shared_ptr<DNA> crossover(shared_ptr<DNA> partner);
  void mutate(float mutationRate);

  char randomCharacter();

  vector<char> genes;
  float fitness;
};
