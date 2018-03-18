#pragma once

#include <algorithm>
#include "BasicVessel.h"

class GeneralVessel : public BasicVessel {
//private:
public:
	real_t fuel;

public:
	GeneralVessel() {}
	GeneralVessel(const OrbitInfo &orbit, real_t angle, real_t fuel)
		: BasicVessel(orbit, angle)
		, fuel(fuel)
	{}

	virtual real_t getMass() const override {
		return 1.0f + 0.5f * fuel;
	}

	virtual real_t setAccRate(real_t _accRate) override {
		const real_t maxAcc = 0.5f;
		_accRate = std::min(maxAcc, std::max(0.0f, _accRate));
		BasicVessel::setAccRate(_accRate);
	}

protected:
	virtual bool burnFuel(real_t df);
	virtual void accelerateByUpdate(real_t df) override;
};
