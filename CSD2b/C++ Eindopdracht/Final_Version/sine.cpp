//
// Created by Ciska Vriezenga on 06/12/2022.
// Filename: sine.cpp
//

#include "sine.h"
#include "math.h"

Sine::Sine() {
}

Sine::Sine(float frequency) {
	setFrequency(frequency);
}

Sine::~Sine() {

}

void Sine::calculate() {
	sample = sin(M_PI * 2 * phase) * amplitude;
}

float Sine::getSample() {
//	sample = 0.01;
	return sample;
}

void Sine::print(int instance) {
	std::cout << "Sine[" << instance << "]" << std::endl;
}