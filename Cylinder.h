class Cylinder {
public:
  virtual real_t getDiameter();
  virtual real_t getRadius();
  virtual real_t getHiratio();
  virtual real_t getHeight();
};

class Cylinder_DH {
protected:
  real_t diameter;
  real_t hiratio;
public:
  virtual real_t getDiameter() {
    return diameter;
  }
  virtual real_t getRadius() {
    return getDiameter() / 2;
  }
  virtual real_t getHiratio() {
    return hiratio;
  }
  virtual real_t getHeight() {
    return getRadius() * getHiratio();
  }
};
