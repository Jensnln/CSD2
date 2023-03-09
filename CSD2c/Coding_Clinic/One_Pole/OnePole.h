//
// Created by Jens on 06/03/2023.
//

#pragma once


struct OnePole{
	OnePole(){};
	~OnePole(){};

	float output(float input){
		y1 = b * input + a * y1;
		return y1;
	}

	void setCoefficient(float coefficient){
		a = coefficient;
		b = 1.0f - a;
	}

private:
	float y1 = { 0.0 };
	float b = { 0.0 };
	float a = { 0.0 };
};
