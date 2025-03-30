#include "Perceptron.h"

void Perceptron::setup(int totalInputs, float learningRate) {
  learningConstant = learningRate;
  for (int i = 0; i < totalInputs; ++i) {
    weights.push_back(ofRandom(-1, 1));
  }
}

int Perceptron::feedforward(vector<float> inputs) {
  float sum = 0;
  for (int i = 0; i < weights.size(); ++i) {
    sum += inputs[i] * weights[i];
  }
  return activate(sum);
}

int Perceptron::activate(float sum) {
  if (sum > 0) {
    return 1;
  } else {
    return -1;
  }
}

void Perceptron::train(vector<float> inputs, int desired) {
  const int guess = feedforward(inputs);
  const int error = desired - guess;
  for (int i = 0; i < weights.size(); ++i) {
    weights[i] += error * inputs[i] * learningConstant;
  }
}
