#pragma once
#include "Particle.h"

class FastParticle : public Particle {


public:
	FastParticle(ofPoint point);

	void DoubleSpeed();

	~FastParticle();
};

