// Filename = melody.h
#pragma once

#include <iostream>
#include "UI.h"

#define NUM_NOTES 16

class Melody {
public:
	Melody();
	~Melody();

	// setters and getters
	float getPitch();

protected:
	// an array of pitches in the E Phrygian dominant scale
	float e_phrygian_dominant_scale[7] = {52, 53, 55, 57, 58, 60, 62};

	// the index of the current note - readIndex
	int index;
};