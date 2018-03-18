#include <algorithm>
#include "VesselView.h"
#include "GeneralVessel.h"

void VesselView::onSetup() {
}

static void renderDashboard_FuelThrehold(const GeneralVessel &vessel) {
	auto fuelrest = vessel.fuel / vessel.getMaxFuel();
	auto threhold = *vessel.accRate;
	glColor3f(0.8f, 0.6f, 0.2f);
	glRectf(-1.0f, -1.0f, -0.85f, -1.0f + 2.0f * fuelrest);
	glColor3f(0.8f, 0.2f, 0.2f);
	glRectf(0.85f, -1.0f, 1.0f, -1.0f +2.0f * threhold);
}

static void glTriangleInRectf(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1) {
	glBegin(GL_TRIANGLES);
	glVertex2f(x0, y0);
	glVertex2f(x1, y0);
	glVertex2f((x1 + x0) * 0.5f, y1);
	glEnd();
}

static void renderVessel(const GeneralVessel &vessel) {

	glPushMatrix();
	glRotatef(vessel.angle - 90.0f, 0, 0, 1);

	glColor3f(0.5f, 0.6f, 0.7f);
	glRectf(-0.2f, -0.4f, 0.2f, 0.4f);

	glColor3f(0.5f, 0.6f, 0.7f);
	glTriangleInRectf(-0.2f, 0.4f, 0.2f, 0.7f);

	if (*vessel.accRate > 0.0f)
	glColor4f(1.0f, 1.0f, 0.6f,
			std::min(*vessel.accRate * 3.0f, 1.0f)),
	glTriangleInRectf(-0.09f, -0.4f, 0.09f, -0.5f);

	if (*vessel.accRate > 0.05f)
	glColor4f(0.9f, 0.8f, 0.3f,
			std::min((*vessel.accRate - 0.05f) * 2.0f, 0.7f)),
	glTriangleInRectf(-0.12f, -0.4f, 0.12f, -0.6f);

	if (*vessel.accRate > 0.4f)
	glColor4f(0.7f, 0.7f, 0.3f,
			std::min((*vessel.accRate - 0.4f) * 0.8f, 0.3f)),
	glTriangleInRectf(-0.16f, -0.43f, 0.16f, -0.75f);

	if (*vessel.accRate > 0.6f)
	glColor4f(0.6f, 0.7f, 0.3f, 0.1f),
	glTriangleInRectf(-0.18f, -0.45f, 0.18f, -0.9f);

	glPopMatrix();
}

void VesselView::onRender() {
	renderDashboard_FuelThrehold(vessel);
	renderVessel(vessel);
}
