#include <iostream>
#include "Orbiter.h"
#include "OrbiteeData.h"

void Orbiter::updatePosvel(real_t dt) {
	using namespace Vectorial;

	auto dth = dt / 2;
	pos += vel * dth;
	if (src)
		src->doAccDv(this, dt);
	pos += vel * dth;
}
