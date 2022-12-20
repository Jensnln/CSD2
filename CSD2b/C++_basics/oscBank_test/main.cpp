/*
  Example program that plays a simple hard coded melody using a square wave oscillator
*/

#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
//#include "square.h"
#include "melody.h"
#include "synth.h"

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

/* 	Function to calculate midi to frequency.
    double mtof(float mPitch)
    {
      // source of the mtof calculation:
      // https://www.musicdsp.org/en/latest/Other/125-midi-note-frequency-conversion.html
      return 440.0 * pow(2.0, (mPitch - 57.0f)/12.0f);
    } // mtof()
*/


/*	Function to update the pitch.
    void updatePitch(Melody& melody, Square& square) {
      float pitch = melody.getPitch();
      double freq = mtof(pitch);
      std::cout << "next pitch: " << pitch << ", freq is: " << freq << std::endl;
//      square.setFrequency(freq);
    } // updatePitch()
*/


    void prepare (double sampleRate) override {
      this->sampleRate=sampleRate;
	  mySynth.init();
	  std::cout << mySynth.getSample();
//		for (int i = 0; i < 20; i++){
//			std::cout << "sample[" << i << "]" << mySynth.getSample();
//			mySynth.tick();
//		}
//      updatePitch(melody,square);
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
//				getSample() +
//				mySynth.getSample() +
				0;
		outputChannels[1][sample] =
//				mySynth.getSample() +
//				getSample() +
				0;
//		mySynth.tick();

		frameIndex ++;
		if(frameIndex >= noteDelayFactor * sampleRate) {
			// reset frameIndex
			frameIndex = 0;

//			Function for updating pitch.
//			updatePitch(melody,square);
		}
	  } // for sample
    } // process()

protected:
	double sampleRate;
	float amplitude = 0.025;
	Melody melody;
	Synth mySynth;
  	int frameIndex = 0;

  /* instead of using bpm and specifying note lenghts we'll make every note
   * equal length and specify the delay between notes in term of the
   * samplerate
   *
   * A note of say 500 msec or 0.5 sec, takes 0.5*samplerate samples to be
   * played
   */
  double noteDelayFactor=0.005;
}; // Callback{}



int main(int argc,char **argv)
{
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

