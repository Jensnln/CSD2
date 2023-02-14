//
// Created by Dean on 27/10/2022.
//

#pragma once
#include "sine.h"

struct Tremolo{
	Tremolo();
	~Tremolo();

    void prepareToPlay (double sampleRate);
    float output (float input);

    void setAmplitude (float amplitude);
    void setRate (float rate);

private:
    Sine osc;
    float amp { 1.0f };
};
