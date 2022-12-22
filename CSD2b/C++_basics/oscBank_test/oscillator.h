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

  	void tick();
  	virtual float getSample() = 0;

  //getters and setters
  	void setFrequency(float frequency);
  	float getFrequency();

	virtual void setPwm(float frequency, float amount);

	// allow to set samplerate after initialization
	void setSampleRate(float sampleRate);
protected:

	// abstract method calculate - needs to be overriden by subclasses
	virtual void calculate() = 0;

	float sample = 0;
	float frequency = 220;
	float amplitude = 1;
	float phase = 0;
	// sample contains the current sample
	 float sampleRate = 44100;


};

#endif
