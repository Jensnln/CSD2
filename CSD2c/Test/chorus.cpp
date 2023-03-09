//
// Created by Jens on 23/02/2023.
//

#include "chorus.h"

Chorus::Chorus() {

	sine.prepareToPlay(sampleRate);
	buffer = new CircBuffer(44100);
}

Chorus::~Chorus() {
}

void Chorus::prepareToPlay(double sampleRate) {
	Effect::prepareToPlay(sampleRate);
	sine.prepareToPlay(sampleRate);
	sine.setDelta(10.0f);


}

void Chorus::calculate(const float& input, float& output) {
//	Make sine unipolar.
	float modSig = (sine.output() + 1) * 0.5f;
//	std::cout << "input2: " << input << std::endl;

//	buffer->setDistance(static_cast <uint> (distance * modSig * depth));
//	std::cout << "The distance is: " << (distance * modSig * depth) << std::endl;
	buffer->input(input);
	buffer->interpolate(buffer->buffer, buffer->readHead - modSig, buffer->currentSize);
	buffer->incrementHeads();
//	std::cout << "output: " <<   buffer->output() << std::endl;
	output = buffer->output();

}

void Chorus::setDepth(float depth) {
	this->depth = depth;
}


