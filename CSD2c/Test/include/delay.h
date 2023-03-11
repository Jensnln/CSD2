//
// Created by Jens on 14/02/2023.
//

#pragma once
#include "utillities.h"
#include "effect.h"
#include "circBuffer.h"

class Delay : public Effect {
public:
	Delay();
	~Delay();

	void calculate(const float& input, float& output) override;
	void setDistance(uint distance);

private:
	CircBuffer* buffer;

};

