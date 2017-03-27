#include <iostream>

#define NDEBUG
#include <GL/freeglut.h>
#include "cScene.h"


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	scena.Init();
	glutMainLoop();

	return 0;
}