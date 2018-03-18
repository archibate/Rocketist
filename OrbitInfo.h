#pragma once

#include "Vector.h"
#include "Orbit.h"

class OrbitInfo {
public:
	real_t semiMajor;
	real_t eccentricity;
	real_t argument;

	OrbitInfo() {}
	OrbitInfo(real_t semiMajor, real_t eccentricity, real_t argument)
		: semiMajor(semiMajor)
		, eccentricity(eccentricity)
		, argument(argument)
	{}

	void calcPosvelAtArgument(Vector2f &pos, Vector2f &vel) const;
	operator Orbit_APZ() const;
};

