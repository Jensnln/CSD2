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

float Delay::output(float input){
	buffer->input(input);
	float output = buffer->output();
	buffer->incrementHeads();

	return output;
}

void Delay::setDistance(uint distance) {
	buffer->setDistance(distance);
}

