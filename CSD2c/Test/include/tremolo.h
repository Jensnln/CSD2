//
// Created by Dean on 27/10/2022.
//

#pragma once
#include <iostream>
#include "effect.h"
#include "sine.h"
#include "utillities.h"

struct Tremolo : public Effect{
	Tremolo();
	~Tremolo();

//	Virtual functions from Effect.
    void prepareToPlay (double sampleRate) override;
	void calculate(const float& input, float& output) override;

//	Set & Get.
    void setAmplitude (float amplitude);
    void setRate (float rate);

private:
    Sine osc;
    float amp { 1.0f };
};
