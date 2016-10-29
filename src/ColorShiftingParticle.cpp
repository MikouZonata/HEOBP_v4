#include "ColorShiftingParticle.h"

ColorShiftingParticle::ColorShiftingParticle() {

}

void ColorShiftingParticle::Update() {
	Particle::Update();
	ShiftColor();
}

void ColorShiftingParticle::ShiftColor() {
	++outsideColor.r;
	++outsideColor.g;
	++outsideColor.b;
}

ColorShiftingParticle::~ColorShiftingParticle(){

}
