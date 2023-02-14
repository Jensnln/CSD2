//
// Created by Jens on 08/02/2023.
//

#include "CircBuffer.h"
#
#include <iostream>

int main() {
//	Make a buffer with a size of 10.
	CircBuffer circBuffer(20);

//	Set the distance to 5.
	circBuffer.setDistance(5);

//	Input 10 samples.
	for (int i = 0; i < 10; i++) {
		circBuffer.input(i);
		circBuffer.incrementHeads();

		std::cout << "Output: " << circBuffer.output() << std::endl;
	}

//	Print output.
//	for (int i = 0; i < 10; i++) std::cout << circBuffer.output() << std::endl;


	return 0;
}