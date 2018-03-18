#include "MapView.h"
#include "BasicVessel.h"
#include "OrbitRender.h"
#include "OrbiteeData.h"
#include "GLCoor.h"
#include "GLColor.h"

void MapView::onSetup() {
}

static void drawOrbiter(const Vector2f &pos) {
	OrbitRender::drawEllipse(pos, 0.03f, 0.03f,
			GLColor3f(0.8f, 0.9f, 0.4f), 2.0f);
}

static void drawOrbitee(const Vector2f &pos) {
	OrbitRender::drawEllipse(pos, 0.03f, 0.03f,
			GLColor3f(0.6f, 0.6f, 0.65f), 5.0f);
}

void MapView::onRender() {

	glPushMatrix();
	glScalef(0.5f, 0.5f, 0.5f);

	GLCoor2f center(0.0f, 0.0f);

	glColor3f(0.7f, 0.8f, 0.9f);
	glPointSize(2.0f);
	OrbitRender::draw(center, orbitAPZ);

	OrbitRender::drawEllipse(center, 0.2f, 0.2f,
			GLColor3f(0.3f, 0.6f, 1.0f), 4.0f);
	for (const auto &orbitee: orbitees) {
		drawOrbitee(orbitee.pos);
	}

	futureTrack.render();

	drawOrbiter(orbiter.pos);

	auto dir = orbiter.getDirection() * 0.03f;

	OrbitRender::drawEllipse(orbiter.pos + dir, 0.02f, 0.02f,
			GLColor3f(0.9f, 1.0f, 0.2f), 2.0f);

	if (orbiter.getAccRate() != 0) {
		OrbitRender::drawEllipse(orbiter.pos - dir, 0.02f, 0.02f,
				GLColor3f(1.0f, 0.5f, 0.1f), 2.0f);
	}

	glPopMatrix();
}
