//
// Created by Jens on 21/12/2022.
//

#ifndef CSD_ADDSYNTH_H
#define CSD_ADDSYNTH_H
#include "synth.h"


class addSynth : public Synth{
public:
	addSynth();
	~addSynth();

protected:
	void loadFreq(float frequency);
	void init();
};

#endif //CSD_ADDSYNTH_H
