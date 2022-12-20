//
// Created by Jens on 20/12/2022.
//

#ifndef CSD_SAW_H
#define CSD_SAW_H
#include <iostream>
#include "oscillator.h"

class Saw : public Oscillator{
public:
	Saw();
	~Saw();

	void calculate();
//	float getSample();

	void print(int instance);
};


#endif //CSD_SAW_H
