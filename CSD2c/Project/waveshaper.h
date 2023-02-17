//
// Created by Jens on 14/02/2023.
//

#pragma once

struct WaveShaper : public Effect {
	WaveShaper();
	~WaveShaper();

	float output(float input);

	void setDrive(float drive);
	void setMix(float mix);
};
