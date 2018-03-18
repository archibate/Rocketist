#pragma once

#include "OrbiterA.h"

class Vessel : public OrbiterA {
public:
	Vessel() {}
	Vessel(const Vector2f &pos, const Vector2f &vel, real_t angle)
		: OrbiterA(pos, vel, angle)
	{}
	Vessel(const Orbiter &orbiter, real_t angle)
		: OrbiterA(orbiter, angle)
	{}
	Vessel(const OrbitInfo &orbit, real_t angle)
		: OrbiterA(orbit, angle)
	{}
};
