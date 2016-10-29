#include "FastParticle.h"

FastParticle::FastParticle(ofPoint point) : Particle(point) {
	DoubleSpeed();
}

void FastParticle::DoubleSpeed(){
	speed *= 4;
}


FastParticle::~FastParticle(){

}
