#pragma once

#include <vector>
#include "OrbiterM.h"

class OrbiterM;

class OrbiteeData {
public:
	std::vector<OrbiterM> *orbitees;
	OrbiteeData()
		: orbitees(nullptr)
	{}
	OrbiteeData(std::vector<OrbiterM> *orbitees)
		: orbitees(orbitees)
	{}

	void doAccDv(Orbiter *self, real_t dt) const;
	void updatePosvels(real_t dt);
};
