#pragma once
#include "Particle.h"

class ParticleReaper
{
public:
	vector<Particle*>* myParticles;

	ParticleReaper(vector<Particle*>*);
	ParticleReaper();

	void SearchAndDestroy();

	~ParticleReaper();
};

