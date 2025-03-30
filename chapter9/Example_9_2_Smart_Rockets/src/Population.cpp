#include "Population.h"

void Population::setup(float _mutationRate, int length, int lifeSpan) {
  mutationRate = _mutationRate;
  generations = 0;

  for (int i = 0; i < length; ++i) {
    const float x = ofGetWidth() * 0.5;
    const float y = ofGetHeight() + 20;
    shared_ptr<DNA> dna = make_shared<DNA>();
    dna->setup(lifeSpan);
    Rocket rocket;
    rocket.setup(x, y, dna);
    population.push_back(rocket);
  }
};

void Population::live() {
  for (int i = 0; i < population.size(); ++i) {
    population[i].run();
  }
};

void Population::fitness(ofVec2f target) {
  for (int i = 0; i < population.size(); ++i) {
    population[i].calculateFitness(target);
  }
};

void Population::selection() {
  float totalFitness = 0;
  for (int i = 0; i < population.size(); ++i) {
    totalFitness += population[i].fitness;
  }

  for (int i = 0; i < population.size(); ++i) {
    population[i].fitness /= totalFitness;
  }
};

void Population::reproduction() {
  vector<Rocket> nextPopulation;
  for (int i = 0; i < population.size(); ++i) {
    shared_ptr<DNA> parentA = weightedSelection();
    shared_ptr<DNA> parentB = weightedSelection();
    shared_ptr<DNA> child = parentA->crossover(parentB);
    child->mutate(mutationRate);

    const float x = ofGetWidth() * 0.5;
    const float y = ofGetHeight() + 20;

    Rocket rocket;
    rocket.setup(x, y, child);
    nextPopulation.push_back(rocket);
  }

  population.clear();
  population = nextPopulation;
  ++generations;
};

void Population::show() {
  for (int i = 0; i < population.size(); ++i) {
    population[i].show();
  }
};

shared_ptr<DNA> Population::weightedSelection() {
  int index = 0;
  float start = ofRandom(1);

  while (start > 0) {
    start = start - population[index].fitness;
    ++index;
  }

  --index;

  return population[index].dna;
};
