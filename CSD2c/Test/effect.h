//
// Created by Jens on 14/02/2023.
//

#pragma once

class Effect {
public:
	Effect();
	~Effect();

	virtual void prepareToPlay (double sampleRate);
	virtual float output(float input);

	void setDryWet(float dryWet);

protected:
	float dryWet = 1.0f;
	float sampleRate;
};
