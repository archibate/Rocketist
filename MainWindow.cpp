#include <memory>
#include <cstdlib>
#include "MainWindow.h"
#include "OpenGL3D.h"

MainWindow::MainWindow()
	: GLUTWindow(nullptr, "Rocketist", 600, 600, -1, -1, 16)
	, mapview(&orbitAPZ, &orbiter, &orbitees)
	, vesselview(&orbiter)
	, orbiteeData(&orbitees)
	, paused(false)
	, speedRate(1)
{}

void MainWindow::onSetup() {
	orbitees.push_back(OrbiterM(Vector2f(0), Vector2f(0), 1.0f));
	orbitees.push_back(OrbiterM(
				OrbitInfo(1.0f, 0.0f, 0.0f), 0.01f));
	orbitees.push_back(OrbiterM(
				OrbitInfo(1.0f, 0.0f, M_PI), 0.01f));

	orbitInfo = OrbitInfo(0.6f, 0.0f, 0.0f);
	orbitAPZ = Orbit_APZ(orbitInfo);
	orbiter = GeneralVessel(orbitInfo, 90.0f, 1.2f);
	orbiter.accRate = &inputAccRate;
	orbiter.src = &orbiteeData;

	changeView(vesselview);
	OpenGL3D::initGL();
}

void MainWindow::onKeyboard(unsigned char key, int x, int y) {
	if (key == 27) { // ESC
		std::exit(0);
	} else if (key == 'm') {
		if (view == &vesselview) {
			changeView(mapview);
		} else if (view == &mapview) {
			changeView(vesselview);
		} else {
			changeView(mapview);
		}
	} else if (key == 'z') {
		inputAccRate.set(inputAccRate + 0.1f);
	} else if (key == 'x') {
		inputAccRate.set(inputAccRate - 0.1f);
	} else if (key == 'a') {
		orbiter.angle += 45.0f;
	} else if (key == 'd') {
		orbiter.angle -= 45.0f;
	} else if (key == ' ') {
		paused = !paused;
	} else if (key == ',') {
		speedRate = (speedRate + 1) / 2;
	} else if (key == '.') {
		speedRate *= 2;
	} else if (key == 'i') {
		mapview.futureTrack.length += 50;
	} else if (key == 'o') {
		mapview.futureTrack.length -= 50;
	} else if (key == 'p') {
		if (mapview.futureTrack.dt == 0.002f) {
			mapview.futureTrack.dt = 0.01f;
			mapview.futureTrack.times = 4;
		} else {
			mapview.futureTrack.dt = 0.002f;
			mapview.futureTrack.times = 6;
		}
	}
}

void MainWindow::onResize(int width, int height) {
	OpenGL3D::resizeGL(width, height);
}

void MainWindow::onTimer(int val) {
	update();
	GLUTWindow::onTimer(val);
}

void MainWindow::update() {
	if (paused)
		return;

	//std::cout << orbiter.pos << " " << orbiter.vel << std::endl;

	auto dt = 0.002f;

	for (int i = 0; i < speedRate; i++) {
		orbiter.updatePosvel(dt);
		orbiteeData.updatePosvels(dt);
	}
}
