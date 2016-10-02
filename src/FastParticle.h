#pragma once
#include "Particle.h"

class FastParticle :
	public Particle
{
public:
	FastParticle();

	void DoubleSpeed();

	~FastParticle();
};

