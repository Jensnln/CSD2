//
// Created by Jens on 14/02/2023.
//

#pragma once
#include <iostream>
#include <cmath>


class Util{
public:
	static float mapInRange(float value, float inMin, float inMax, float outMin, float outMax){
		return (value - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
	}

	static int testF(int number){
		return number + 1;
	}

	static float linearMap(float factor, float min, float max){
		return mapInRange(factor, 0.0, 1.0, min , max);
	}

protected:
	Util() {};
	~Util() {};

};

