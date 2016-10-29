#pragma once
#include "ofMain.h"

class Particle
{
public:
	const int minPulseSpeed = 1, maxPulseSpeed = 3, minLifetime = 2, maxLifetime = 5, minSpeed = -1.8, maxSpeed = 1.8;
	int pulseSpeed, lifetime;
	//Index number for this particle's location in the vector.
	//The time in seconds a circle stays active before expiring.
	//The minimum and maximum lifetime of a circle.
	//The speed at which the circle expands and retracts in seconds/full cycle.
	//The minimum and maximum values for both x and y speeds
	
	const float maxRadius = 8;
	float currentRadius, pulseCounter = 0, lifetimeCounter = 0;
	//The base radius of the circle.

	ofPoint position, speed;
	//Current position of the circle.
	//The distance the circle travels every frame in px/second. This also indicates the direction the circle is moving.

	const ofColor centerColor = ofColor(255, 255, 255, 255), auraColor = (255, 255, 255, 20);
	ofColor outsideColor;
	//Colors for the inside and outside of the circle in RGB and Alpha values.

	bool isAlive = true;
	//Has this particle expired?
	
	Particle(ofPoint);
	//Calls SetValues to set the base values. See SetValues.
	Particle();
	//Default Constructor, don't use.

	virtual void SetValues(ofPoint);
	//Sets position to tempPosition, received from Spawner.
	//Sets centerColor to white (0,0,0,1).
	//Sets radius.
	//Sets lifetime, pulseSpeed, speed and outsideColor to appropriate random values.

	virtual void Update();
	//Calls Pulse().
	//Adds 1 to lifetimeCounter.
	//If lifetimeCounter >= lifetime calls Expire.

	virtual void Move();
	//Changes position according to speed.

	void Pulse();
	//Runs a abs(sin(time)) to change the radius of the circle.

	void Draw() const;
	//Draws outer circle.
	//Draws inner circle.

	void Expire();

	~Particle();
	//Deletes circle and cleans up the mess.
};

