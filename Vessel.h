#pragma once

#include "OrbiterA.h"

class Vessel : public OrbiterA {
private:
	real_t accRate;

public:
	Vessel() {}
	Vessel(const OrbitInfo &orbit, real_t angle)
		: OrbiterA(orbit, angle)
		, accRate(0)
	{}

	real_t getAccRate() const {
		return accRate;
	}

	virtual real_t setAccRate(real_t _accRate) {
		accRate = _accRate;
	}

	virtual real_t getMass() const {
		return 1.0f;
	}

	void updatePosvel(real_t dt) {
		OrbiterA::updatePosvel(dt);
		if (accRate != 0)
			accelerateByUpdate(accRate * dt);
	}

protected:
	virtual void accelerateByUpdate(real_t df) {
		vel += getDirection() * (df / getMass());
	}
};
