//
// Created by Jens on 14/02/2023.
//

#include "effect.h"

Effect::Effect() {
}
Effect::~Effect() {
}

void Effect::prepareToPlay(double sampleRate) {
	this->sampleRate = sampleRate;
}


void Effect::setDryWet(float dryWet) {
//	Set range to 0-1.
	if(dryWet > 1) dryWet = 1;
	else if(dryWet < 0) dryWet = 0;
	this->dryWet = dryWet;
}

float Effect::output(float input) {
	return input;
}