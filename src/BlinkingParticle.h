#pragma once
#include "Particle.h"

class BlinkingParticle :
	public Particle
{
public:
	BlinkingParticle();
	~BlinkingParticle();

	int moveCounter = 0, moveTimer = 10;

	void Move();
};

