//
// Created by Jens on 14/02/2023.
//

#include "Utillities.h"
#include "jack_module.h"

class Callback : public AudioCallback {
	void prepare (int sampleRate) override {
	}
void process (AudioBuffer buffer) override {
	}

private:
//	std::array<Effect, 1> effects;
};

int main(){
	auto callback = Callback {};
	auto jack = JackModule (callback);

	// start jack client with 2 inputs and 2 outputs
	jack.init (2, 2);

	bool running = true;
	while (running) {
		switch (std::cin.get()) {
			case 'q':
				running = false;
				break;
		}
	}

	return 0;
}