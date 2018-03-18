#pragma once

#include <GL/glut.h>
#include "GLUTWindow.h"

class GLUTApp {
protected:
	auto_ptr<GLUTWindow> window;
public:
	GLUTApp() {}
	GLUTApp(int *pargc, char *argv[], auto_ptr<GLUTWindow> &window)
		: window(window)
	{
		init(pargc, argv);
	}

	void init(int *pargc, char *argv[]) {
		glutInit(pargc, argv);
		window->init();
	}
};

