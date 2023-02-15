//
// Created by Dean on 27/10/2022.
//

#pragma once
#include "effect.h"
#include "sine.h"

struct Tremolo : public Effect{
	Tremolo();
	~Tremolo();

    void prepareToPlay (double sampleRate) override;
    float output (float input) override;

    void setAmplitude (float amplitude);
    void setRate (float rate);

private:
    Sine osc;
    float amp { 1.0f };
};
