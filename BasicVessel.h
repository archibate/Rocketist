#pragma once

#include "Vessel.h"

class BasicVessel : public Vessel {
private:
	real_t accRate;

public:
	BasicVessel() {}
	BasicVessel(const OrbitInfo &orbit, real_t angle)
		: Vessel(orbit, angle)
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

	void updatePosvel(real_t dt);

protected:
	virtual void accelerateByUpdate(real_t df);
};
