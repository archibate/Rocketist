#pragma once

#include "GLView.h"

class GeneralVessel;

class VesselView : public GLView {
private:
	GeneralVessel &vessel;

public:
	VesselView(GeneralVessel *vessel)
		: vessel(*vessel)
	{}

public:
	virtual void onSetup() override;
	virtual void onRender() override;
};

