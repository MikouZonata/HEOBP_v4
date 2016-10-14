#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "ParticleReaper.h"
#include <vector>

class Spawner
{
public:
	float spawnRate, turnRate, currentRotation;
	//Amount of circles spawned per minute.
	//The rotation speed of the spawner around its center in degrees/second.
	//Self explanatory.

	int spawnCounter = 0, spawnTimer = 8;
	//Adds up every frame.
	//When spawnCounter >= spawnTimer a circle is spawned and spawnCounter resets to 0.

	ofPoint basePosition, spawnPosition;
	ofVec2f spawnRadius;
	//Base position of the spawner in the center of the screen.
	//The current position at which circles are spawned if spawnCounter allows it. See RotateSpawner and SpawnCircle.

	vector<Particle>* myParticles = new vector<Particle>;
	//The vector for containing particles.
	unsigned int maxParticles = 50;
	//Maximum ammount of particles a spawner can create.

	ParticleReaper myReaper;

	Spawner();
	//Calls SetPattern.

	void SetPattern();
	//Gets screen size (height and width in px).
	//Determines screen center and spawning pattern radius.

	void Update();
	//Will be called 60 times/second.
	//Calls RotateSpawnPosition.
	//Calls SpawnCircle.

	void RotateSpawnPosition();
	//Adds turnRate to the currentRotation.
	//Calculates the spawnPosition based on a distance from the basePosition and the currentRotation.

	void SpawnParticle();
	//Adds 1 to spawnCounter.
	//If spawnCounter >= spawnTimer it spawns a circle at spawnPosition and sets spawnCounter back to 0.

	void Draw();
	//Used to draw a clean background every frame.

	~Spawner();
	//Cleans up the mess.
};

