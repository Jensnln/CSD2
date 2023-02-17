//
// Created by Jens on 14/02/2023.
//

#pragma once

class Effect {
public:
	Effect();
	~Effect();

	void process(const float& input, float& output);

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
