#include "OrbitInfo.h"

void OrbitInfo::calcPosvelAtArgument(Vector2f &pos, Vector2f &vel) const {
	using namespace Vectorial;

	auto distance = semiMajor * (1 - eccentricity);
	Vector2f posdir(-std::cos(argument), -std::sin(argument));
	pos = posdir * distance;

	auto velocity = std::sqrt(2 / distance - 1 / semiMajor);
	Vector2f veldir(std::sin(argument), -std::cos(argument));
	vel = veldir * velocity;
}

OrbitInfo::operator Orbit_APZ() const {
	auto semiFocus = semiMajor * eccentricity / 2;
	auto ap = semiMajor + semiFocus;
	auto pe = semiMajor - semiFocus;
	return Orbit_APZ(ap, pe, argument);
}

