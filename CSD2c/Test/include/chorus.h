//
// Created by Jens on 23/02/2023.
//

#pragma once
#include "effect.h"
#include "sine.h"
#include "circBuffer.h"

class Chorus : public Effect {
public:
	Chorus();
	~Chorus();

	void calculate(const float& input, float& output) override;
	void prepareToPlay(double sampleRate) override;

	void setDepth(float depth);

protected:
	int distance = 3;
	float depth = 1;
	Sine sine;
	CircBuffer* buffer;
};
