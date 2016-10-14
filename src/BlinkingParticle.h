#pragma once
#include "Particle.h"

class BlinkingParticle : public Particle {

	using Particle::Particle;

public:
	BlinkingParticle();

	~BlinkingParticle();

	int moveCounter = 0, moveTimer = 10;

	void Move();
};

