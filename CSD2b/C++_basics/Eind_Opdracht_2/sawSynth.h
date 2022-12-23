//
// Created by Jens on 21/12/2022.
//

#ifndef CSD_SAWSYNTH_H
#define CSD_SAWSYNTH_H
#include "synth.h"

class sawSynth : public Synth{
public:
	sawSynth();
	~sawSynth();


protected:
	void init();
	void loadFreq(float frequency);
	float detune = 0.0;
};
#endif //CSD_SAWSYNTH_H
