#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
//#include "audioToFile.h"
#include "oscillator.h"
#include "callback.h"

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */


int main(int argc, char **argv) {
  auto callback = CustomCallback{};
  auto jackModule = JackModule{callback};


  jackModule.init(0, 2);

  bool running = true;
  while (running) {
    switch (std::cin.get()) {
      case 'q':
        running = false;
    }
  }
  //end the program
  return 0;
} // main()

