//
// Created by Jens on 14/02/2023.
//

#pragma once

class Effect {
public:
	Effect();
	~Effect();

	void process(float& input, float& output);


	virtual void prepareToPlay (double sampleRate) = 0;
	virtual float output(float input);

	void setDryWet(float dryWet);
	void setBypass(bool bypass);

protected:

	float input;
	float sampleRate;
	float dryWet = 1.0f;
	bool bypass = false;
};
