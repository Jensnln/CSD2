// Filename: square.h
// Created by Ciska Vriezenga on 06/12/2022.
//


#ifndef BLOK2B_SQUARE_H
#define BLOK2B_SQUARE_H

#include "oscillator.h"
#include "sine.h"

class Square : public Oscillator{
public:
	Square();
	~Square();
	float getSample();
	Sine pwmSine = Sine(2);
	void setPwm(float frequency, float amount);


protected:
	void calculate();
	float pwmAmt;
};

#endif //BLOK2B_SQUARE_H
