#pragma once

#include "Particle.h"
#include <vector>
#include <iterator>
#include <stdarg.h>

class ParticleReaper
{
public:
	vector<Particle>* myParticles;

	ParticleReaper(vector<Particle>*);
	ParticleReaper();

	void Update();

	void CleanUp(vector<Particle>::iterator);

	~ParticleReaper();
};

