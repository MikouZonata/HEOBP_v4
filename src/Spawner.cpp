#include "Spawner.h"

Spawner::Spawner() {
	SetValues();
	myReaper = ParticleReaper(myParticles);
}

void Spawner::SetValues() {
	spawnTimer = 2;
	turnRate = 2;
	maxParticles = 90;

	basePosition = ofPoint(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
	spawnRadius = ofVec2f(0, 240);
}

void Spawner::Update() {
	RotateSpawnPosition();
	SpawnParticle();

	for (int i = 0; i < myParticles.size(); i++) {
		if (myParticles.at(i)->isAlive == true) {
			myParticles.at(i)->Update();
		}
	}

	myReaper.Update();
	cout << "Particle vector size: " << myParticles.size() << "\n";
}

void Spawner::RotateSpawnPosition() {
	spawnRadius.rotate(turnRate);
	spawnPosition = basePosition + spawnRadius;
}

void Spawner::SpawnParticle() {
	++spawnCounter;

	if (spawnCounter >= spawnTimer) {
		if (myParticles.size() < maxParticles) {
			myParticles.push_back(new Particle(spawnPosition));
			spawnRadius.y *= -1;
			spawnRadius.x *= -1;
		}
		spawnCounter = 0;
	}
}

void Spawner::Draw() {
	for (vector<Particle*>::iterator i = myParticles.begin(); i != myParticles.end(); i++) {
		if ((*i)->isAlive == true) {
			(*i)->Draw();
		}
	}
}

Spawner::~Spawner() {

}
