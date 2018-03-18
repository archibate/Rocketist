#pragma once

#include "Orbiter.h"

class OrbiterA : public Orbiter {
public:
	real_t angle;

	OrbiterA() {}
	OrbiterA(const OrbitInfo &orbit, real_t angle)
		: Orbiter(orbit)
		, angle(angle)
	{}
	OrbiterA(const Orbiter &orbiter, real_t angle)
		: Orbiter(orbiter)
		, angle(angle)
	{}
	OrbiterA(const Vector2f &pos, const Vector2f &vel, real_t angle)
		: Orbiter(pos, vel)
		, angle(angle)
	{}

	Vector2f getDirection() const {
		return Vector2f(std::cos(M_PI / 180 * angle),
				std::sin(M_PI / 180 * angle));
	}
};

