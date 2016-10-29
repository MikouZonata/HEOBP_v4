#include "Spawner.h"

Spawner::Spawner() {
	SetValues();
	myReaper = ParticleReaper(myParticles);
}

void Spawner::SetValues() {
	basePosition = ofPoint(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
	spawnRadius = ofVec2f(0, 240);
}

Spawner* Spawner::Instance() {
	if (!singleton) {
		singleton = new Spawner();
	}
	return singleton;
}

void Spawner::Update(){
	RotateSpawnPosition();
	SpawnParticle();

	for (vector<Particle*>::iterator i = myParticles->begin(); i != myParticles->end(); i++) {
		if ((*i)->isAlive == true) {
			(*i)->Update();
		}
	}

	myReaper.SearchAndDestroy();
}

void Spawner::RotateSpawnPosition() {
	spawnRadius.rotate(turnRate);
	spawnPosition = basePosition + spawnRadius;
}

void Spawner::SpawnParticle() {
	++spawnCounter;

	if (spawnCounter >= spawnTimer) {
		if (myParticles->size() < maxParticles) {
			unsigned int particlePicker = ofRandom(3) / 1;
			switch (particlePicker) {
			case 0:
				myParticles->push_back(new Particle(spawnPosition));
				break;
			case 1:
				myParticles->push_back(new FastParticle(spawnPosition));
				break;
			case 2:
				myParticles->push_back(new ColorShiftingParticle(spawnPosition));
				break;
			default:
				break;
			}

			spawnRadius.y *= -1;
			spawnRadius.x *= -1;
		}
		spawnCounter = 0;
	}
}

void Spawner::Draw() const{
	for (vector<Particle*>::iterator i = myParticles->begin(); i != myParticles->end(); i++) {
		if ((*i)->isAlive == true) {
			(*i)->Draw();
		}
	}
}

Spawner* Spawner::singleton = 0;

Spawner::~Spawner() {

}