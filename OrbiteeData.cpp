#include "OrbiteeData.h"

void OrbiteeData::doAccDv(Orbiter *that, real_t dt) const {
	using namespace Vectorial;

	for (const auto &orbitee: *orbitees) {
		if (&orbitee == that)
			continue;
		auto dis = orbitee.pos - that->pos;
		auto sca = dis % dis;
		sca = dt * orbitee.mass / (sca * std::sqrt(sca));
		that->vel += dis * sca;
	}
}

void OrbiteeData::updatePosvels(real_t dt) {
	using namespace Vectorial;

	auto dth = dt / 2;

	for (auto &orbitee: *orbitees) {
		//orbitee.updatePosvel();
		orbitee.pos += orbitee.vel * dth;
		doAccDv(&orbitee, dt);
		orbitee.pos += orbitee.vel * dth;
	}
}
