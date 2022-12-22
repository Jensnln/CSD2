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


//	Function to call form main.cpp to gather the samples for all synth types.
	float getSample();
//	Function to change the frequency from main.cpp in the subclasses.
	void setFreq(float frequency);
//	Function to set the sampleRate from main.cpp.
	void setSampleRate();
//	Function to tick all the type of synths.
	void tick();
	int getSineAmt();

//	Initialzes all standard stuff and is a pass through for functions.
	virtual void init();
//	Virtual functions to load the frequency into base class specific ways.
	virtual void loadFreq(float frequency);

//	Array to hold the amount of oscillators from each type
	int amt[3];
	int fundamental;
	float sampleVal;
	float sampleRate = 44100;
	float amplitude = 0.25;
	float frequency;

//	Allocating a pointer that to store pointers to a 2D array to hold osc pointers.
	Oscillator** oscBank[3];


};

#endif //CSD_SYNTH_H
