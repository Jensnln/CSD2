//
// Created by Jens on 16/12/2022.
//

#ifndef CSD_SYNTH_H
#define CSD_SYNTH_H
#include <iostream>
#include "sine.h"
#include "square.h"

class Synth{
public:
	Synth(float fundamental, int sineAmount, int squareAmount);
	~Synth();

	void init();
	float getSample();
	void question();

//	Make a pointer that points to an oscillator pointer.
//	Name that pointer oscBank
//	Let it oscBank point to an array of oscillator pointers with the size of oscAmount.
	Oscillator** oscBank[2];



protected:
	float fundamental;
	int sineAmount;
	int squareAmount;
	int oscAmount;
};

#endif //CSD_SYNTH_H
