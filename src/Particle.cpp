#include "Particle.h"

Particle::Particle(unsigned int myIndexTemp, vector<Particle>& myArrayTemp, ofPoint tempPosition)
{
	myIndex = myIndexTemp;
	myArrayPointer = &myArrayTemp;
	SetValues(tempPosition);
}

//STEP RIGHT UP FOLKS, SET YA VALUES HERE
void Particle::SetValues(ofPoint tempPosition)
{
	position = tempPosition;

	minLifetime = 1;
	maxLifetime = 6;
	lifetime = ofRandom(maxLifetime - minLifetime) + minLifetime;

	minPulseSpeed = 1;
	maxPulseSpeed = 3;
	pulseSpeed = ofRandom(maxPulseSpeed - minPulseSpeed) + minPulseSpeed;

	minSpeed = -1.5;
	maxSpeed = 1.5;
	speed.x = ofRandom(maxSpeed - minSpeed) + minSpeed;
	speed.y = ofRandom(maxSpeed - minSpeed) + minSpeed;

	outsideColor.r = ofRandom(255);
	outsideColor.g = ofRandom(255);
	outsideColor.b = ofRandom(255);
	outsideColor.a = 210;
}

void Particle::Update()
{
	Move();

	++lifetimeCounter;
	if (lifetime <= lifetimeCounter) {

	}

	Pulse();
}

void Particle::Move() {
	position.x += speed.x;
	position.y += speed.y;
}

void Particle::Pulse() {
	currentRadius = abs(sin(ofGetElapsedTimef() * pulseSpeed)) * maxRadius;
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
	myArrayPointer->erase(myArrayPointer->at(index));
}

Particle::~Particle()
{
}
