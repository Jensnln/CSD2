//
// Created by Jens on 14/02/2023.
//

#pragma once
#include "Utillities.h"
#include "CircBuffer.h"

class Delay : public Effect {
public:
	Delay();
	~Delay();

	float output(float input);
private:
	CicrBuffer* buffer;

};

