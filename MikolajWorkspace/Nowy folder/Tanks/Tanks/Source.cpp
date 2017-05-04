#include "Turret.h"
#include "Tank.h"
#include "GL/freeglut.h"
#include "Scene.h"

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	scene.Init();
	glutMainLoop();

	return 0;
}
