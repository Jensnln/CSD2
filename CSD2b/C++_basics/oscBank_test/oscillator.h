// Filename: oscillator.h
// Base class of the oscillators

#ifndef _Oscillator_H_
#define _Oscillator_H_
#include <iostream>

class Oscillator
{
public:
  	Oscillator();
  	~Oscillator();



//  float getSample();
  	void tick();

  	virtual void print(int instance) = 0;

  	virtual float getSample();

  //getters and setters
  	void setFrequency(float frequency);
  	float getFrequency();

	// allow to set samplerate after initialization
	void setSamplerate(float samplerate);
protected:

	// abstract method calculate - needs to be overriden by subclasses
	virtual void calculate() = 0;
	float sample = 0.1;
	float frequency = 220;
	float amplitude = 0.2;
	float phase = 0;
	// sample contains the current sample
	// float samplerate = 44100;
};

#endif
