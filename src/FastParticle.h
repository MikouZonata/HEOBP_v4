#pragma once
#include "Particle.h"

class FastParticle : public Particle {

	using Particle::Particle;

public:
	FastParticle();

	void DoubleSpeed();

	~FastParticle();
};

