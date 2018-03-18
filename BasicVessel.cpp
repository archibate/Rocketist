#include "BasicVessel.h"

void BasicVessel::accelerateByUpdate(real_t df) {
	vel += getDirection() * (df / getMass());
}

void BasicVessel::updatePosvel(real_t dt) {
	OrbiterA::updatePosvel(dt);
	if (accRate != 0)
		accelerateByUpdate(accRate * dt);
}
