#include "ParticleReaper.h"

ParticleReaper::ParticleReaper(vector<Particle*> particlesTemp){
	myParticles = particlesTemp;
}

ParticleReaper::ParticleReaper() {
}

void ParticleReaper::Update() {

	for (vector<Particle*>::iterator i = myParticles.begin(); i != myParticles.end(); i++) {
		if ((*i)->isAlive == false) {
			CleanUp(i);
			break;
		}
	}
}

void ParticleReaper::CleanUp(vector<Particle*>::iterator index) {
	myParticles.erase(index);
	// MEMORY LEAK :D:D:D:D:D Investigate unique_ptr
	Update();
}


ParticleReaper::~ParticleReaper(){

}