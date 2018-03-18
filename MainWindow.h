#pragma once

#include "GLUTWindow.h"
#include "MapView.h"
#include "VesselView.h"
#include "OrbiteeData.h"
#include "GeneralVessel.h"

class MainWindow : public GLUTWindow {
private:
	MapView mapview;
	VesselView vesselview;

	GeneralVessel orbiter;
	OrbitInfo orbitInfo;
	Orbit_APZ orbitAPZ;

	class InputAccRate : public VirInputf {
public:
		InputAccRate() {
			set(0);
		}
		virtual void set(const real_t &t) override {
			VirInputf::set(std::min(1.0f, std::max(0.0f, t)));
		}
	} inputAccRate;

	std::vector<OrbiterM> orbitees;
	OrbiteeData orbiteeData;

	bool paused;
	int speedRate;

public:
	MainWindow();
protected:
	virtual void onSetup() override;
	virtual void onResize(int width, int height) override;
	virtual void onKeyboard(unsigned char key, int x, int y) override;
	virtual void onTimer(int val) override;
	void update();
};
