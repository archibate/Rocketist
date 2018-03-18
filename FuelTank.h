#pragma once

class FuelTank {
public:
	virtual real_t getLiqHydrogen() const = 0;
	virtual real_t getLiqOxygen() const = 0;
	virtual real_t costLiqHydrogen(real_t t) = 0;
	virtual real_t costLiqOxygen(real_t t) = 0;
};

static costFuel(real_t fuel_orig, real_t t) {
	auto fuel = std::max(fuel_orig - t, 0);
	return fuel - fuel_orig;
}

class FuelTank_HO : public FuelTank {
protected:
	real_t liqOxygen;
	real_t liqHydrogen;
public:
	FuelTank_HO(real_t liqOxygen, real_t liqHydrogen)
		: liqOxygen(liqOxygen)
		, liqHydrogen(liqHydrogen)
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
