#include "melody.h"

Melody::Melody() {}

Melody::~Melody() {}

float Melody::getPitch() {
	// wrap index back to the beginning
	if (index >= NUM_NOTES) {
		index = 0;
	}

	// get the lowest pitch in the scale
	float lowest_pitch = e_phrygian_dominant_scale[0];

	// generate a new melody by selecting the lowest pitch or a random pitch from the scale
	float pitch;
	if (index % 3 == 0) {
		pitch = lowest_pitch;
	} else {
		pitch = e_phrygian_dominant_scale[rand() % 6 + 1];
	}
	index++;
	return pitch;
}