#pragma once
#include "Particle.h"

class ColorShiftingParticle : public Particle {

	using Particle::Particle;

public:
	ColorShiftingParticle();

	void Update();

	void ShiftColor();

	~ColorShiftingParticle();
};

