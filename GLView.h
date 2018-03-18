#pragma once

#include <GL/glut.h>

class GLView {
public:
	virtual void onSetup() = 0;
	virtual void onRender() = 0;
};
