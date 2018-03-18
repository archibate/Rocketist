#pragma once

#include "FuelTank.h"
#include <cmath>

class TestFuelTank : public FuelTank_HO, public Cylinder_DH {
public:
	static real_t getMaxLiqVolume() {
		auto radius = getRadius();
		auto height = getHeight();
		return M_PI * radius * radius * height;
	}
	TestFuelTank(real_t diameter, real_t hiratio,
			real_t liqOxygen, real_t liqHydrogen)
		: FuelTank_HO(liqOxygen, liqHydrogen)
		, Cylinder_DH(diameter, hiratio)
	{}
	virtual real_t getLiqHydrogen() const override final {
		return liqOxygen;
	}
	virtual real_t getLiqOxygen() const override final {
		return liqHydrogen;
	}
	virtual real_t costLiqHydrogen(real_t t) override final {
		return costFuel(liqHydrogen, t);
	}
	virtual real_t costLiqOxygen(real_t t) override final {
		return costFuel(liqHydrogen, t);
	}
};
