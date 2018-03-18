#include "GLUTWindow.h"
#include "GLView.h"

void GLUTWindow::init() {
	glutInitDisplayMode(DISPLAY_MODE);
	if (xSize != -1 && ySize != -1)
		glutInitWindowSize(xSize, ySize);
	if (xPosition != -1 && yPosition != -1)
		glutInitWindowPosition(xPosition, yPosition);
	glutCreateWindow(caption.c_str());

	onSetup();
	initFuncs();
	setTimer();
}

GLUTWindow *g_this_ptr;

void GLUTWindow::initFuncs() {
	g_this_ptr = this; // well...
	glutDisplayFunc(displayFunc);
	glutKeyboardFunc(keyboardFunc);
}

void GLUTWindow::displayFunc() {
	g_this_ptr->onDisplay();
}

void GLUTWindow::keyboardFunc(unsigned char key, int x, int y) {
	g_this_ptr->onKeyboard(key, x, y);
}

void GLUTWindow::timerFunc(int val) {
	g_this_ptr->onTimer(val);
	g_this_ptr->setTimer();
}

void GLUTWindow::resizeFunc(int width, int height) {
	g_this_ptr->onResize(width, height);
}

void GLUTWindow::onDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	view->onRender();
	flushDisplay();
}

void GLUTWindow::onTimer(int val) {
	refreshDisplay();
}

void GLUTWindow::setTimer() {
	if (timerInterval > 0)
		glutTimerFunc(timerInterval, timerFunc, 1);
}

void GLUTWindow::defaultOnResize(int width, int height) {
	xSize = width;
	ySize = height;
}

void GLUTWindow::changeView(GLView &_view) {
	view = &_view;
	view->onSetup();
}
