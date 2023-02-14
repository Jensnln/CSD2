//
// Created by Jens on 14/02/2023.
//

#pragma once

class Effect {
public:
	Effect();
	~Effect();

	void prepare (int sampleRate);

	void input(float input);
	float output();

	void setDryWet(float dryWet);
protected:
	float dryWet = 1.0f;
	float sampleRate;
};
