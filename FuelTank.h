class FuelTank {
public:
  virtual real_t getLiquidHydrogen() const = 0;
  virtual real_t getLiquidOxygen() const = 0;
  virtual real_t costLiquidHydrogen(real_t t) = 0;
  virtual real_t costLiquidOxygen(real_t t) = 0;
};

class FuelTank_HO : public FuelTank {
protected:
  real_t liquidOxygen;
  real_t liquiqHydrogen;
public:
  virtual real_t getLiquidHydrogen() const override final {
    return liquidOxygen;
  }
  virtual real_t getLiquidOxygen() const override final {
    return liquidHydrogen;
  }
  virtual real_t costLiquidHydrogen(real_t t) override final {
    return liquidHydrogen -= t;
  }
  virtual real_t costLiquidOxygen(real_t t) override final {
    return liquidOxygen -= t;
  }
};
