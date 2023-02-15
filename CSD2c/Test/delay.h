//
// Created by Jens on 14/02/2023.
//

#pragma once
#include "utillities.h"
#include "circBuffer.h"

class Delay{
public:
	Delay();
	~Delay();

	void setDistance(uint distance);

	float output(float input);
private:
	CircBuffer* buffer;

};

