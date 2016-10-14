#include "ParticleReaper.h"

ParticleReaper::ParticleReaper(vector<Particle>* particlesTemp){
	myParticles = particlesTemp;
}

void ParticleReaper::Update() {

	for (vector<Particle>::iterator i = myParticles->begin(); i != myParticles->end(); i++) {
		if (i->isAlive == false) {
			CleanUp(i);
			break;
		}
	}
}

void ParticleReaper::CleanUp(vector<Particle>::iterator index) {
	myParticles->erase(index);
	Update();
}


ParticleReaper::~ParticleReaper(){

}
