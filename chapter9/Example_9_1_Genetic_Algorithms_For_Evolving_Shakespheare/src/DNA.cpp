#include "DNA.h"

void DNA::setup(int length) {
  fitness = 0;

  for (int i = 0; i < length; ++i) {
    genes.push_back(randomCharacter());
  }
};

string DNA::getPhrase() { return string(genes.begin(), genes.end()); };

void DNA::calculateFitness(string target) {
  float score = 0;
  for (int i = 0; i < genes.size(); ++i) {
    if (genes[i] == target[i]) {
      ++score;
    }
  }
  fitness = score / target.size();
};

shared_ptr<DNA> DNA::crossover(shared_ptr<DNA> partner) {
  shared_ptr<DNA> child = make_shared<DNA>();
  child->setup(genes.size());

  int midpoint = floor(ofRandom(genes.size()));

  for (int i = 0; i < genes.size(); ++i) {
    if (i < midpoint) {
      child->genes[i] = genes[i];
    } else {
      child->genes[i] = partner->genes[i];
    }
  }
  return child;
};

void DNA::mutate(float mutationRate) {
  for (int i = 0; i < genes.size(); ++i) {
    if (ofRandom(1) < mutationRate) {
      genes[i] = randomCharacter();
    }
  }
};

char DNA::randomCharacter() {
  char c = floor(ofRandom(32, 127));
  return c;
}
