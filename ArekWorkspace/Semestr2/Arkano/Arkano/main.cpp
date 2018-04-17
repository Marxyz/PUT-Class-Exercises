#include <iostream>
#include <GL/freeglut.h>
#include "Scena.h"
#include <ctime>

using namespace std;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	scena.Inicjuj();
	glutMainLoop();

	cout << "Zdobyto " << scena.punktacja << " punktow. GRATULACJE!" << endl;
	return 0;
}