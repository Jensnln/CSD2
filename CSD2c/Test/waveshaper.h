//
// Created by Jens on 14/02/2023.
//

#pragma once
#include "utillities.h"
#include "effect.h"
#include "writeToFile.h"

using uint = unsigned int;

struct WaveShaper : public Effect {
	WaveShaper();
	WaveShaper(uint size);
	~WaveShaper();

	int setChannel(int chan);

	void calculate(const float& input, float& output) override;
//	void prepareToPlay (double sampleRate) override;

	void setDrive(float k);

private:
	int chan;
	float k = 1;
	uint bufferSize;
	float* buffer;

};
