#pragma once

#include <GL/glut.h>
#include "Vector.h"

struct GLCoor2f : public Vector2f {
	GLCoor2f() {}
	GLCoor2f(Vector2f v)
		: Vector2f(v)
	{}
	GLCoor2f(GLfloat x, GLfloat y)
		: Vector2f(x, y)
	{}
};
