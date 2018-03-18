#include <iostream>
#include <cmath>
#include "OrbitRender.h"
#include "GLCoor.h"
#include "GLColor.h"

#define ISF(x) (x * 100)
#define IOF(x) ((x + 1.0f) * 100)
#define FOI(i) (i * 0.01f - 1.0f)
#define FSF(x) (x * 0.01f)

static void setPixel2i(int x, int y)
{
	glVertex2f(FOI(x), FOI(y));
}

/*
 * http://blog.csdn.net/u012866328/article/details/52607439
 * 椭圆4路对称
 */
static void Ellipsepot4i(int x0, int y0, int x, int y)
{
	// 1
	setPixel2i((x0 + x), (y0 + y));
	// 2
	setPixel2i((x0 + x), (y0 - y));
	// 3
	setPixel2i((x0 - x), (y0 - y));
	// 4
	setPixel2i((x0 - x), (y0 + y));
}

/*
 * 中点画椭圆算法
 */
static void MidPoint_Ellipse(int x0, int y0, int a, int b)
{
	float a2 = a * a;
	float b2 = b * b;

	float d = b2 + a2 * (0.25f - b);
	int x = 0;
	int y = b;
	Ellipsepot4i(x0, y0, x, y);
	// 1
	while (b2 * (x + 1) < a2 * (y - 0.5f)) {
		if (d < 0) {
			d += b2 * (2 * x + 3);
		} else {
			d += (b2 * (2 * x + 3) + a2 * (-2 * y + 2));
			--y;
		}
		++x;
		Ellipsepot4i(x0, y0, x, y);
	}
	d = (b * (x + 0.5f)) * 2 + (a * (y - 1)) * 2 - (a * b) * 2;
	// 2
	while (y > 0) {
		if (d < 0) {
			d += b2 * (2 * x + 2) + a2 * (-2 * y + 3);
			++x;
		} else {
			d += a2 * (-2 * y + 3);
		}
		--y;
		Ellipsepot4i(x0, y0, x, y);
	}
}

void OrbitRender::drawEllipse(GLCoor2f center, real_t a, real_t b, GLColor3f color, real_t thickness = 0) {
	if (thickness)
		glPointSize(thickness);
	glColor3f(color.x, color.y, color.z);
	glBegin(GL_POINTS);
	drawEllipse(center, a, b);
	glEnd();
}

void OrbitRender::drawEllipse(GLCoor2f center, real_t a, real_t b) {
	MidPoint_Ellipse(IOF(center.x), IOF(center.y), ISF(a), ISF(b));
}

void OrbitRender::draw(GLCoor2f center, const Orbit_APZ &orbit) {
	auto a = orbit.getLR(), c = orbit.getHF();
	auto b = std::sqrt(a * a - c * c);

	center.x += c;
	glPushMatrix();
	glRotatef(orbit.az, 0, 0, 1);
	drawEllipse(center, a, b);
	glPopMatrix();
}
