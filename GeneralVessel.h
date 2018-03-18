#pragma once

#include <algorithm>
#include "Vessel.h"

class GeneralVessel : public Vessel {
//private:
public:
	real_t fuel;

public:
	GeneralVessel() {}
	GeneralVessel(const OrbitInfo &orbit, real_t angle, real_t fuel)
		: Vessel(orbit, angle)
		, fuel(fuel)
	{}

	virtual real_t getMass() const override {
		return 1.0f + 0.5f * fuel;
	}

	virtual real_t setAccRate(real_t _accRate) override {
		const real_t maxAcc = 0.5f;
		_accRate = std::min(maxAcc, std::max(0.0f, _accRate));
		Vessel::setAccRate(_accRate);
	}

protected:
	virtual bool burnFuel(real_t df);
	virtual void accelerateByUpdate(real_t df) override;
};
