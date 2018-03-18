#pragma once

#include "Orbiter.h"

class OrbiterM : public Orbiter {
public:
	real_t mass;

	OrbiterM() {}
	OrbiterM(const OrbitInfo &orbit, real_t mass)
		: Orbiter(orbit)
		, mass(mass)
	{}
	OrbiterM(const Vector2f &pos, const Vector2f &vel, real_t mass)
		: Orbiter(pos, vel)
		, mass(mass)
	{}
};
