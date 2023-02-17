//
// Created by Jens on 14/02/2023.
//

#include "effect.h"

Effect::Effect() {
}
Effect::~Effect() {
}

void Effect::prepareToPlay(double sampleRate) {}

void Effect::process(float& input, float& output) {
	if (bypass) output = input;
	else output = (input * dryWet) + output * (1.0f - dryWet);
}


void Effect::setDryWet(float dryWet) {
//	Set range to 0-1.
	if(dryWet > 1) dryWet = 1;
	else if(dryWet < 0) dryWet = 0;
	this->dryWet = dryWet;
}

void Effect::setBypass(bool bypass) {
	this->bypass = bypass;
}

float Effect::output(float input) {
	return input;
}