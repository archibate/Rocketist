#pragma once

#include "BasicVessel.h"

class GeneralVessel : public BasicVessel {
public:
	real_t fuel;

public:
	GeneralVessel() {}
	GeneralVessel(const OrbitInfo &orbit, real_t angle, real_t fuel)
		: BasicVessel(orbit, angle)
		, fuel(fuel)
	{}

	virtual real_t getMaxAcc() const {
		return 0.5f;
	}

	virtual real_t getMaxFuel() const {
		return 1.2f;
	}

	virtual real_t getMass() const override {
		return 1.0f + 0.5f * fuel;
	}

protected:
	virtual bool burnFuel(real_t df);
	virtual void accelerateByUpdate(real_t df) override;
};
