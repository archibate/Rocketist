#pragma once

#include <vector>
#include "GLView.h"
#include "FutureTrackRender.h"
#include "BasicVessel.h"

class OrbiterM;
class Orbit_APZ;

class MapView : public GLView {
private:
	const Orbit_APZ &orbitAPZ;
	const BasicVessel &orbiter;
	const std::vector<OrbiterM> &orbitees;

public:
	FutureTrackRender futureTrack;

	MapView(const Orbit_APZ *orbitAPZ, const BasicVessel *orbiter,
			const std::vector<OrbiterM> *orbitees)
		: orbitAPZ(*orbitAPZ)
		, orbiter(*orbiter)
		, orbitees(*orbitees)
		, futureTrack(static_cast<const Orbiter *>(orbiter), orbitees)
	{}

public:
	virtual void onSetup() override;
	virtual void onRender() override;
};
