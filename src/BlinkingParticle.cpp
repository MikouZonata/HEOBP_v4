#include "BlinkingParticle.h"

BlinkingParticle::BlinkingParticle(){

}

void BlinkingParticle::Move() {
	++moveCounter;

	if (moveCounter >= moveTimer) {
		position += speed * 4;
		moveCounter = 0;
	}
}

BlinkingParticle::~BlinkingParticle(){

}
