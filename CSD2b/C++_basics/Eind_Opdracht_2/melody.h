#pragma once

#include <iostream>
#include "UI.h"


#define NUM_NOTES 16

class Melody
{
public:
	Melody();
	~Melody();

	// setters and getters
	float getPitch();

protected:


	// Cmaj7 -  arpeggio
//	float melody[NUM_NOTES] = {60, 64, 67, 71, 64, 67, 64, 60, 55};

	float melody[NUM_NOTES] = {48, 52, 48, 55, 52, 59, 52, 60, 64, 59, 48, 55, 48, 52, 48, 55,
							   };

	// the index of the current note - readIndex
	int index;
};
