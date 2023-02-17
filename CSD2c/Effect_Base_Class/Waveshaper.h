//
// Created by Jens on 14/02/2023.
//

#ifndef CSD_WAVESHAPER_H
#define CSD_WAVESHAPER_H
using unsigned int uint;

class Waveshaper : public Effect {
public:
	Waveshaper(uint size);
	~Waveshaper();

	void setDrive(float k);
	float output(float input);
	void calculate(float input);


protected:
	float* buffer;
	uint bufferSize;
	float input;
	float k = 1;
	float shape;

private:
	inline float mapInRange(float value, float inMin, float inMax, float outMin, float outMax);{
		return (value - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
	}
	inline float linearMap(float value, float inMin, float inMax, float outMin, float outMax);{
		return (value - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
	}
};

#endif //CSD_WAVESHAPER_H
