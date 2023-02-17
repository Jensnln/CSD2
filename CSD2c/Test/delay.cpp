//
// Created by Jens on 14/02/2023.
//

#include "delay.h"
Delay::Delay() {
	buffer = new CircBuffer(44100 * 10);
}

Delay::~Delay() {
	delete buffer;
}

void Delay::calculate(const float& input, float& output) {
//	Delayed sample (value at readhead).
	auto delay = buffer->output();

//	Write the input to the buffer (value to writehead).
	buffer->input(input);

//	Increment the read and write heads.
	buffer->incrementHeads();

//	Apply the delayed sample to the output.
	output = delay;
}

void Delay::setDistance(uint distance) {
	buffer->setDistance(distance);
}

