#include "FutureTrackRender.h"
#include "OrbiteeData.h"
#include "OrbitRender.h"
#include "GLCoor.h"
#include "GLColor.h"

void FutureTrackRender::render() {
	Orbiter ves = orbiter;

	std::vector<OrbiterM> obtes = orbitees;
	OrbiteeData obteData(&obtes);
	ves.src = &obteData;

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < times; j++) {
			ves.updatePosvel(dt);
			obteData.updatePosvels(dt);
		}
		OrbitRender::drawEllipse(ves.pos, 0.02f, 0.02f,
				GLColor3f(0.9f, 0.2f, 0.8f), 1.3f);
		for (const auto &obte: obtes) {
			OrbitRender::drawEllipse(obte.pos, 0.02f, 0.02f,
					GLColor3f(0.5f, 0.3f, 0.6f), 1.3f);
		}
	}
}
