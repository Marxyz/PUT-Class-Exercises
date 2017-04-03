#include <iostream>
#define NDEBUG
#include <GL/freeglut.h>
#include <vector>
#include <ctime>
#include "Prostokat.h"
#include <cstdlib>

bool Prostokat::czyKliknieta(float x, float y)
{
	return abs(x - _x) <= 1.0* _dlugosc / 2 && abs(y - _y) <= 1.0*_wysokosc / 2;
}
void Prostokat::Draw()
{

	glPushMatrix();
	glTranslated(_x, _y, 0);
	glRotated(_alpha, 0.0, 0.0, 1.0);
	glColor3d(c_r, c_g, c_b);
	glBegin(GL_POLYGON);
	{

		glVertex3d(1.0 * -_dlugosc / 2, _wysokosc / 2, 0);

		glVertex3d(_dlugosc / 2, _wysokosc / 2, 0);

		glVertex3d(_dlugosc / 2, -_wysokosc / 2, 0);

		glVertex3d(-_dlugosc / 2, -_wysokosc / 2, 0);
	}
	glEnd();
	glPopMatrix();
}

Prostokat::Prostokat(int dlugosc, int wysokosc, double speed) : Figura(speed), _dlugosc(dlugosc), _wysokosc(wysokosc)
{
}

Prostokat::Prostokat() : Figura(0.1), _dlugosc(1), _wysokosc(1)
{
}
