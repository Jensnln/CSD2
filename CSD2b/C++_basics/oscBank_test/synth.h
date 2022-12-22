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

	virtual void init();
	float getSample();
	void tick();

//	void setFreq();
	void setFreq(float frequency);
	void setSampleRate();

	int amt[3];
	int fundamental;
	float sampleVal;
	float sampleRate = 44100;
	float amplitude = 0.25;

	Oscillator** oscBank[3];


};

#endif //CSD_SYNTH_H
