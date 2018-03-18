#pragma once

#include "Vessel.h"
#include "VirInput.h"

class BasicVessel : public Vessel {
public:
	const VirInputf *accRate;

public:
	BasicVessel() {}
	BasicVessel(const OrbitInfo &orbit, real_t angle)
		: Vessel(orbit, angle)
	{}

	virtual real_t getMass() const {
		return 1.0f;
	}

	void updatePosvel(real_t dt);

protected:
	virtual void accelerateByUpdate(real_t df);
};
