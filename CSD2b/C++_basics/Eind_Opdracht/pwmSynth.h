//
// Created by Jens on 21/12/2022.
//

#ifndef CSD_PWMSYNTH_H
#define CSD_PWMSYNTH_H
#include "synth.h"
#include <iostream>

class pwmSynth : public Synth{
public:
	pwmSynth();
	~pwmSynth();

	void init();
	void loadFreq(float frequency);
	void setPwm();


};

#endif //CSD_PWMSYNTH_H
