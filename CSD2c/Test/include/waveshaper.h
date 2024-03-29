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

	void calculate(const float& input, float& output) override;

	void setDrive(float k);

private:
	float k = 1.0f;
	uint bufferSize;
	float* buffer;

};
