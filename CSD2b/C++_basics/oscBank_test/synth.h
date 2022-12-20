//
// Created by Jens on 20/12/2022.
//

#ifndef CSD_SYNTH_H
#define CSD_SYNTH_H
#include "sine.h"
#include "square.h"

class Synth{
public:
	Synth();
	~Synth();

	void init();

	int amt[3];

	int sineAmt;
	int squareAmt;
	int oscAmt;
	int fundamental;

};

#endif //CSD_SYNTH_H
