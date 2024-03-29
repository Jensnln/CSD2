//
// Created by Jens on 14/02/2023.
//

#pragma once
#include <iostream>

class Effect {
public:
	Effect();
	~Effect();

//	Process an effect (bypass and calculate).
	void process(const float& input, float& output);

//	calculate the effect (needs to be overridden).
	virtual void calculate(const float& input, float& output) = 0;
	virtual void prepareToPlay (double sampleRate);

	void setDryWet(float dryWet);
	void setBypass(bool bypass);

protected:
	float input;
	float sampleRate;
	float dryWet = 1.0f;
	bool bypass = false;
};
