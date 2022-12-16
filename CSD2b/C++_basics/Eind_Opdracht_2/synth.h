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
	Synth(float fundamental);
	~Synth();
	void init();
//	float getSample();

//	Declare what how many oscillators of what type you want.
	int sineAmount = 0;
	int squareAmount = 0;

//	Calculate the total amount of oscillators.
	int oscAmount = sineAmount + squareAmount;

	float getSample();
//	Make a pointer that points to an oscillator pointer.
//	Name that pointer oscBank
//	Let it oscBank point to an array of oscillator pointers with the size of oscAmount.
	Oscillator** oscBank;


protected:
	float fundamental;
};

#endif //CSD_SYNTH_H
