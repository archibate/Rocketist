#pragma once

#include "Orbit.h"

struct GLCoor2f;
struct GLColor3f;

namespace OrbitRender {
	void draw(GLCoor2f center, const Orbit_APZ &orbit);
	void drawEllipse(GLCoor2f center, real_t a, real_t b, GLColor3f color, real_t thickness);
	void drawEllipse(GLCoor2f center, real_t a, real_t b);
};
