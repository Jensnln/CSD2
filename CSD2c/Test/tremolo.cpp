//
// Created by Jens on 14/02/2023.
//

#include "tremolo.h"

Tremolo::Tremolo() {}

Tremolo::~Tremolo() {}

void Tremolo::prepareToPlay (double sampleRate) {
	Effect::prepareToPlay(sampleRate);
	osc.prepareToPlay(sampleRate);
	osc.setDelta(1.0);
}

void Tremolo::calculate(const float& input, float& output) {
//	Mod signal is osc output.
	auto modSignal = osc.output();
	modSignal *= amp;
	modSignal += 1.0f - amp;
	output = input * modSignal;
}

void Tremolo::setAmplitude (float amplitude) {
	amp = amplitude;
}

void Tremolo::setRate (float rate) {
	osc.setDelta(rate);
}




