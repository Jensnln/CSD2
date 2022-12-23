// Filename: Oscillator.cpp
#include "oscillator.h"
#include "math.h"

Oscillator::Oscillator() {}

Oscillator::~Oscillator() {}

void Oscillator::setSampleRate(float sampleRate) {
	this->sampleRate = sampleRate;
}

float Oscillator::getSample() {
	return sample;
}


void Oscillator::setFrequency(float frequency) {
	this->frequency = frequency;
}

float Oscillator::getFrequency() {
	return frequency;
}

void Oscillator::tick() {
	// Increment the phase to allow calculation of next sample
	phase += frequency / sampleRate;
	// wrap the phase to interval [0, 1]
	if (phase > 1) phase -= 1.0;
	// calculate sample for the incremented phase
	calculate();
}

void Oscillator::setPwm(float frequency, float amount) {}

void Oscillator::setAmp(float amplitude) {
	this->amplitude = amplitude;
}

float Oscillator::getAmp() {
	return amplitude;
}