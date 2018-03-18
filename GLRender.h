#pragma once

#include <GL/glut.h>

class GLRender {
public:
	GLRender() {}
	virtual void render() = 0;
};
