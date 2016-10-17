#include "Particle.h"

Particle::Particle(ofPoint tempPosition)
{
	SetValues(tempPosition);
}

Particle::Particle() {
	//Default Constructor
	SetValues(ofPoint(0, 0));
}

//STEP RIGHT UP FOLKS, SET YA VALUES HERE
void Particle::SetValues(ofPoint tempPosition)
{
	position = tempPosition;

	minLifetime = 2;
	maxLifetime = 5;
	lifetime = ofRandom(maxLifetime - minLifetime) + minLifetime;

	minPulseSpeed = 1;
	maxPulseSpeed = 3;
	pulseSpeed = ofRandom(maxPulseSpeed - minPulseSpeed) + minPulseSpeed;

	minSpeed = -1.8;
	maxSpeed = 1.8;

	speed.x = ofRandom(maxSpeed - minSpeed) + minSpeed;
	speed.y = ofRandom(maxSpeed - minSpeed) + minSpeed;
	while (speed.x == 0 && speed.y == 0) {
		speed.x = ofRandom(maxSpeed - minSpeed) + minSpeed;
		speed.y = ofRandom(maxSpeed - minSpeed) + minSpeed;
	}

	outsideColor.r = ofRandom(255);
	outsideColor.g = ofRandom(255);
	outsideColor.b = ofRandom(255);
	outsideColor.a = 210;
}

void Particle::Update()
{
	Move();

	lifetimeCounter += ofGetLastFrameTime();
	if (lifetime <= lifetimeCounter) {
		Expire();
	}

	Pulse();
}

void Particle::Move() {
	position.x += speed.x;
	position.y += speed.y;
}

void Particle::Pulse() {
	pulseCounter += ofGetLastFrameTime();
	currentRadius = abs(sin(pulseCounter * pulseSpeed)) * maxRadius;
}

void Particle::Draw()
{
	ofSetColor(auraColor);
	ofDrawCircle(position, currentRadius * 4);

	ofSetColor(outsideColor);
	ofDrawCircle(position, currentRadius * 2);

	ofSetColor(centerColor);
	ofDrawCircle(position, currentRadius * 0.5);
}

void Particle::Expire() {
	isAlive = false;
}

Particle::~Particle()
{
}
