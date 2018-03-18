#pragma once

//#include "GLRender.h"
#include "real.h"
#include <vector>

class Orbiter;
class OrbiterM;

class FutureTrackRender /*: public GLRender*/ {
private:
	const Orbiter &orbiter;
	const std::vector<OrbiterM> &orbitees;
public:
	int length;
	real_t dt;
	int times;

	FutureTrackRender(const Orbiter *orbiter,
			const std::vector<OrbiterM> *orbitees)
		: orbiter(*orbiter)
		, orbitees(*orbitees)
		, length(0)
		, dt(0.008f)
		, times(5)
	{}

	/*virtual */void render()/* override*/;
};
