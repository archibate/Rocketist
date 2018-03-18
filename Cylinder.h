#pragma once

class Cylinder {
public:
	virtual real_t getDiameter() const = 0;
	virtual real_t getRadius() const = 0;
	virtual real_t getHiratio() const = 0;
	virtual real_t getHeight() const = 0;
};

class Cylinder_DH : public Cylinder {
protected:
	real_t diameter;
	real_t hiratio;
public:
	Cylinder_DH(real_t diameter, real_t hiratio)
		: diameter(diameter)
		, hiratio(hiratio)
	{}
	virtual real_t getDiameter() const override final {
		return diameter;
	}
	virtual real_t getRadius() const override final {
		return getDiameter() / 2;
	}
	virtual real_t getHiratio() const override final {
		return hiratio;
	}
	virtual real_t getHeight() const override final {
		return getRadius() * getHiratio();
	}
};
