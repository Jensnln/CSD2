//
// Created by Jens on 14/02/2023.
//

#ifndef CSD_EFFECT_H
#define CSD_EFFECT_H

class Effect {
public:
	Effect();
	~Effect();

	void setDryWet(float dryWet);
	void input(float value);
	float output();




//	virutal void calulateFrame(float input)

protected:
	float dryWet;
};

#endif //CSD_EFFECT_H
