//
// Created by Jens on 16/12/2022.
//

#ifndef CSD_FMSYNTH_H
#define CSD_FMSYNTH_H
#include <iostream>
#include "synth.h"

class fmSynth : public Synth{
public:
	fmSynth();
	~fmSynth();

	void init();

	float getSample();
protected:
};

#endif //CSD_FMSYNTH_H
