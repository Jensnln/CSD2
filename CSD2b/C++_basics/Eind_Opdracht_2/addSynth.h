//
// Created by Jens on 16/12/2022.
//

#ifndef CSD_ADDSYNTH_H
#define CSD_ADDSYNTH_H
#include <iostream>
#include "synth.h"
#include "sine.h"
#include "square.h"


class addSynth : public Synth{
public:
	addSynth(float fundamental);
	~addSynth();

	void init();
	float getSample();

};

#endif //CSD_ADDSYNTH_H
