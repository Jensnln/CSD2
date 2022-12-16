#ifndef _Oscillator_H_
#define _Oscillator_H_
#include <iostream>

class Oscillator
{
public:
  Oscillator();
  ~Oscillator();



  float getSample();
  void tick();

  //getters and setters
  void setFrequency(float frequency);
  float getFrequency();

	// allow to set samplerate after initialization
	void setSamplerate(float samplerate);

protected:
  // abstract method calculate - needs to be overriden by subclasses
  virtual void calculate() = 0;
  float frequency = 220;
  float amplitude = 0.2;
  float phase = 0;
  // sample contains the current sample
  float sample = 0;
  float samplerate = 44100;
};

#endif
