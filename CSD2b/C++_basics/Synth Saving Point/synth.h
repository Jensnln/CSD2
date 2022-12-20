//
// Created by Jens on 20/12/2022.
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

	void init();
	float getSample();

	int amt[3];

	int sineAmt;
	int squareAmt;
	int sawAmt;
	int oscAmt;
	int fundamental;

	Oscillator** oscBank[3];


};

#endif //CSD_SYNTH_H
