//
// Created by Jens on 14/02/2023.
//

#pragma once

class Effect {
public:
	Effect();
	~Effect();

	void input(float input);
	float output();

	void setDryWet(float dryWet);
};
