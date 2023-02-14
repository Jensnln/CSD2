//
// Created by Jens on 13/02/2023.
//

// Mapinrange():
#include <cmath>
#include <iostream>

// Mapinrange function.
double mapInRange(double factor, double inMin, double inMax, double outMin, double outMax){
	double slope = (outMax - outMin) / (inMax - inMin);
	return outMin + slope * (factor - inMin);
}

// Linearmap function.
double linearMap(double factor, double min, double max){
//	Scaling:
	return mapInRange(factor, 0.0, 1.0, min , max);
}


int main(){
	double answer = mapInRange(50, 0, 100, 25, 50);
	double answer2 = linearMap(0.5, 100, 200);

	std::cout << answer << std::endl;
	std::cout << answer2 << std::endl;
	return 0;
}
