// File name: main.ccp
// Making the synth playing it in the callback class.

#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
//#include "square.h"
#include "melody.h"
#include "synth.h"
#include "addSynth.h"
#include "sawSynth.h"
#include "pwmSynth.h"
#define NROFSYNTHS 2

//Synth mySynth;
addSynth myAddSynth;
sawSynth mySawSynth;
pwmSynth myPwmSynth;

/*
 * NOTE: the development library with headers for jack2 needs to be installed to build this program.
 *
 * When built, before running the program start jackd, the JACK audio server daemon.
 *
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 *
 * start jackd : jackd -d <backend>
 * where backend is e.g. coreaudio (MacOS) or alsa (Linux)
 *
 * Alternatively there are graphical clients that start jackd.
 */



class Callback : public AudioCallback
{

public:

// 	Function to calculate midi to frequency.
    double mtof(float mPitch)
    {
      // source of the mtof calculation:
      // https://www.musicdsp.org/en/latest/Other/125-midi-note-frequency-conversion.html
	  double freqVal = 440.0 * pow(2.0, (mPitch - 57.0f)/12.0f);

      return freqVal /4;
    } // mtof()



//	Function to update the pitch.
    void updatePitch(Melody& melody, Synth& synth) {
      float pitch = melody.getPitch();
      double freq = mtof(pitch);
      std::cout << "next pitch: " << pitch << ", freq is: " << freq << std::endl;
	  synth.setFreq(freq);
//      myPwmSynth.setFreq(freq);

    } // updatePitch()


	float getAllSample(){
		float sampleVal = 0;

		sampleVal +=
//				myAddSynth.getSample() +
//				mySawSynth.getSample() +
				myPwmSynth.getSample() +
				//	mySynth.getSample() +
				0;

		return sampleVal;
	}


    void prepare (double sampleRate) override {
      this->sampleRate=sampleRate;
      updatePitch(melody,myPwmSynth);
    } // prepare()


    /*
     * process() gets called by the JACK engine.
     *
     * If you are interested in incoming audio, use inputChannels[channel][sample]
     * For sending audio to the output(s), use outputChannels[channel][sample]
     */
    void process (AudioBuffer buffer) override {
        auto [inputChannels,
			  outputChannels,
			  numInputChannels,
			  numOutputChannels,
			  numFrames]
			  = buffer;


	for (int sample = 0; sample < numFrames; sample++){
		outputChannels[0][sample] =
				getAllSample() +
//				myAddSynth.getSample() +
//				mySawSynth.getSample() +
//				myPwmSynth.getSample() +
//				getSample() +
				0;
		outputChannels[1][sample] =
				getAllSample() +
//				myAddSynth.getSample() +
//				mySawSynth.getSample() +
//				myPwmSynth.getSample() +
//				getSample() +
				0;
//		myAddSynth.tick();
//		mySawSynth.tick();
		myPwmSynth.tick();
		frameIndex ++;
		if(frameIndex >= noteDelayFactor * sampleRate) {
			// reset frameIndex
			frameIndex = 0;
			std::cout << frameIndex;

//			Function for updating pitch.
			updatePitch(melody,myPwmSynth);
		}
	  } // for sample
    } // process()

protected:
	double sampleRate;
	float amplitude = 0.025;
	Melody melody;
  	int frameIndex = 0;

  /* instead of using bpm and specifying note lenghts we'll make every note
   * equal length and specify the delay between notes in term of the
   * samplerate
   *
   * A note of say 500 msec or 0.5 sec, takes 0.5*samplerate samples to be
   * played
   */
  double noteDelayFactor=0.1;
}; // Callback{}



int main(int argc,char **argv)
{
//	Synth mySynth;
//	myAddSynth.init();
//	mySawSynth.init();
	myPwmSynth.init();
//	synthBank[0]->init();
  auto callback = Callback {};
  auto jack_module = JackModule(callback);

  jack_module.init(1,2);

  std::cout << "\n\nType 'quit' to exit\n";
  bool running = true;
  while (running) {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        break;
    }
  } // while

  return 0;

} // main()




