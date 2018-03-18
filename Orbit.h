#pragma once

#include "real.h"
#include <cmath>

struct Orbit_AP {
	real_t ap;
	real_t pe;

	Orbit_AP() {}
	Orbit_AP(real_t ap, real_t pe)
		: ap(ap), pe(pe)
	{}
	real_t getAP() const {
		return ap;
	}
	real_t getPE() const {
		return pe;
	}
	real_t getLD() const {
		auto ap = getAP(), pe = getPE();
		return ap + pe;
	}
	real_t getLR() const {
		return getLD() / 2;
	}
	real_t getSR2() const {
		auto a = getLR(), c = getHF();
		return a * a - c * c;
	}
	real_t getSR() const {
		return std::sqrt(getSR2());
	}
	real_t getSD() const {
		return getSR() * 2;
	}
	real_t getHF() const {
		auto ap = getAP(), pe = getPE();
		return ap - pe;
	}
	real_t getEC() const {
		return getHF() / getLR();
	}
};

struct Orbit_APZ : public Orbit_AP {
	real_t az;

	Orbit_APZ() {}
	Orbit_APZ(real_t ap, real_t pe, real_t az)
		: Orbit_AP(ap, pe), az(az)
	{}
	real_t getAZ() const {
		return az;
	}
};
