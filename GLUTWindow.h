#pragma once

#include <GL/glut.h>
#include <string>

class GLView;

#ifndef DISPLAY_MODE
#define DISPLAY_MODE (GLUT_DOUBLE | GLUT_RGBA)
//#define DISPLAY_MODE (GLUT_SINGLE | GLUT_RGBA)
#endif

class GLUTWindow {
private:
	int xSize, ySize;
	int xPosition, yPosition;
	std::string caption;
protected:
	GLView *view;
	int timerInterval;

public:
	GLUTWindow(GLView *view = nullptr,
			std::string caption = "OpenGL Window",
			int xSize = -1, int ySize = -1,
			int xPosition = -1, int yPosition = -1,
			int timerInterval = 0)
		: xSize(xSize), ySize(ySize)
		, xPosition(xPosition), yPosition(yPosition)
		, caption(caption)
		, timerInterval(timerInterval)
	{}

	void init();
	void mainloop() {
		glutMainLoop();
	}
	void flushDisplay() {
#if DISPLAY_MODE & GLUT_DOUBLE
		glutSwapBuffers();
#else
		glFlush();
#endif
	}
	void refreshDisplay() {
		glutPostRedisplay();
	}
	int getXSize() const {
		return xSize;
	}
	int getYSize() const {
		return ySize;
	}
	void changeView(GLView &view);

private:
	void setTimer();
	void initFuncs();
	void defaultOnResize(int width, int height);

	static void displayFunc();
	static void keyboardFunc(unsigned char key, int x, int y);
	static void resizeFunc(int width, int height);
	static void timerFunc(int val);

protected:
	virtual void onResize(int width, int height) {}
	virtual void onSetup() {}
	virtual void onDisplay();
	virtual void onKeyboard(unsigned char key, int x, int y) {}
	virtual void onTimer(int val);
};

