#include "ParticleReaper.h"

ParticleReaper::ParticleReaper(vector<Particle*>* particlesTemp){
	myParticles = particlesTemp;
}

ParticleReaper::ParticleReaper() {
}

void ParticleReaper::SearchAndDestroy(){
	for (vector<Particle*>::iterator i = myParticles->begin(); i != myParticles->end();) {
		if ((*i)->isAlive == false) {
			delete (*i);
			i = myParticles->erase(i);
		}
		else {
			i++;
		}
	}
}

ParticleReaper::~ParticleReaper(){

}