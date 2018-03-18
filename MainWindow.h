#pragma once

#include "GLUTWindow.h"
#include "MapView.h"
#include "VesselView.h"
#include "OrbiteeData.h"

class MainWindow : public GLUTWindow {
private:
	MapView mapview;
	VesselView vesselview;

	GeneralVessel orbiter;
	OrbitInfo orbitInfo;
	Orbit_APZ orbitAPZ;

	std::vector<OrbiterM> orbitees;
	OrbiteeData orbiteeData;

	bool paused;

public:
	MainWindow();
protected:
	virtual void onSetup() override;
	virtual void onResize(int width, int height) override;
	virtual void onKeyboard(unsigned char key, int x, int y) override;
	virtual void onTimer(int val) override;
	void update();
};
