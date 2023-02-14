//
// Created by Jens on 14/02/2023.
//

#include "Tremolo.h"

Tremolo::Tremolo() {}

Tremolo::~Tremolo() {}

void Tremolo::prepareToPlay (double sampleRate) {
	osc.prepareToPlay(sampleRate);
	osc.setDelta(2.0);
}

float Tremolo::output (float input) {
	auto modSignal = osc.output();
	modSignal *= amp;
	modSignal += 1.0f - amp;
	return input * modSignal;
}

void Tremolo::setAmplitude (float amplitude) {
	amp = amplitude;
}

void Tremolo::setRate (float rate) {
	osc.setDelta(rate);
}




