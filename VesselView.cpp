#include "VesselView.h"

void VesselView::onSetup() {
}

void VesselView::onRender() {

	glColor3f(0.5f, 0.6f, 0.7f);
	glRectf(-0.2f, -0.2f, 0.2f, 0.2f);

	auto fuelrest = vessel.fuel;
	auto threhold = vessel.getAccRate();
	glColor3f(0.8f, 0.6f, 0.2f);
	glRectf(0.8f, -1.0f, 1.0f, -1.0f + fuelrest);
	glRectf(0.8f, -1.0f, 1.0f, -1.0f + threhold);
}
