#pragma once

#include "Vector.h"
#include "OrbitInfo.h"

class OrbiteeData;

class Orbiter {
public:
	Vector2f pos;
	Vector2f vel;
	const OrbiteeData *src;

	Orbiter(const OrbiteeData *src = nullptr)
		: src(src)
	{}
	Orbiter(const Vector2f &pos, const Vector2f &vel)
		: pos(pos), vel(vel)
	{}
	Orbiter(real_t semiMajor, real_t eccentricity, real_t argument)
		: Orbiter(OrbitInfo(semiMajor, eccentricity, argument))
	{}
	explicit Orbiter(const OrbitInfo &orbit) {
		orbit.calcPosvelAtArgument(pos, vel);
	}
	void updatePosvel(real_t dt);
private:
	void getDvBySrc(Vector2f &src, real_t dt);
};
