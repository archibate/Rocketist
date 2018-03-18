#pragma once

#include <GL/glut.h>
#include "Vector.h"

struct GLColor3f : public Vector3f {
	GLColor3f() {}
	GLColor3f(Vector3f v)
		: Vector3f(v)
	{}
	GLColor3f(GLfloat x, GLfloat y, GLfloat z)
		: Vector3f(x, y, z)
	{}
};
