//
// Created by Jens on 20/12/2022.
// Filename: synth.h
//

#ifndef CSD_SYNTH_H
#define CSD_SYNTH_H
#include "sine.h"
#include "square.h"
#include "saw.h"

class Synth{
public:
	Synth();
	~Synth();

	void init();
	float getSample();
	void tick();
	void setFreq();

	int amt[3];

	int sineAmt;
	int squareAmt;
	int sawAmt;
	int oscAmt;
	int fundamental;
	float sampleVal;

	Oscillator** oscBank[3];


};

#endif //CSD_SYNTH_H
