#include <iostream>
#include <memory>
#include <cstdlib>
#include "MainWindow.h"
#include "VectorIOStream.h"

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);

	MainWindow win;

	win.init();
	win.mainloop();
}
