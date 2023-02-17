//
// Created by Jens on 14/02/2023.
//

#pragma once

struct WaveShaper : public Effect {
	WaveShaper();
	~WaveShaper();

	void calculate(const float& input, float& output) override;
//	void prepareToPlay (double sampleRate) override;

private:
	float k = 1;

};
