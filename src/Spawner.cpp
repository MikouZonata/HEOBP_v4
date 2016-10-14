#include "Spawner.h"

Spawner::Spawner() {
	spawnCounter = spawnTimer;
	SetPattern();
	myReaper = ParticleReaper(myParticles);
}

void Spawner::SetPattern() {
	spawnRate = ofRandom(10 * 100, 60 * 100) / 100;
	turnRate = ofRandom(0.5 * 100, 3 * 100) / 100;

	basePosition = ofPoint(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
	spawnRadius = ofVec2f(ofRandom(10, 450), ofRandom(10, 450));
}

void Spawner::Update() {
	RotateSpawnPosition();
	SpawnParticle();

	for (int i = 0; i < myParticles->size(); i++) {
		if (myParticles->at(i).isAlive == true) {
			myParticles->at(i).Update();
		}
	}
}

void Spawner::RotateSpawnPosition() {
	spawnRadius.rotate(turnRate);
	spawnPosition = basePosition + spawnRadius;
}

void Spawner::SpawnParticle() {
	++spawnCounter;

	if (spawnCounter >= spawnTimer) {
		if (myParticles->size() < maxParticles) {
			myParticles->push_back(Particle(spawnPosition));
		}
		spawnCounter = 0;
	}
}

void Spawner::Draw() {
	for (int i = 0; i < myParticles->size(); i++) {
		if (myParticles->at(i).isAlive == true) {
			myParticles->at(i).Draw();
		}
	}
}

Spawner::~Spawner() {

}
