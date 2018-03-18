#pragma once

#include <vector>
#include "GLView.h"
#include "Vessel.h"

class OrbiterM;

class MapView : public GLView {
private:
	const Orbit_APZ &orbitAPZ;
	const Vessel &vessel;
	const std::vector<OrbiterM> &orbitees;
public:
	int lengthFutureTrack;

public:
	MapView(const Orbit_APZ *orbitAPZ, const Vessel *vessel,
			const std::vector<OrbiterM> *orbitees)
		: orbitAPZ(*orbitAPZ)
		, vessel(*vessel)
		, orbitees(*orbitees)
		, lengthFutureTrack(0)
	{}

private:
	void plotFutureTrack();

public:
	virtual void onSetup() override;
	virtual void onRender() override;
};
