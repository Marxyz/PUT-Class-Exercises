#include "Trojkat.h"
#include <GL/freeglut.h>
#include <cstdlib>


void Trojkat::Draw()
{
	glPushMatrix();
	glTranslated(_x, _y, 0);
	glRotated(_alpha, 0, 0, 1);
	glPushMatrix();
	glTranslated(0, -1.0*_wysokosc / 2, 0);
	glColor3d(c_r, c_g, c_b);
	glBegin(GL_POLYGON);
	{
		glVertex3d(-1.0*_podstawa / 2, 0, 0);
		glVertex3d(0, _wysokosc, 0);
		glVertex3d(1.0*_podstawa / 2, 0, 0);
	}
	glEnd();
	glPopMatrix();
	glPopMatrix();
}

Trojkat::Trojkat() : Figura(0.01), _podstawa(1), _wysokosc(1)
{
}

Trojkat::Trojkat(double wysokosc, double podstawa, double speed) : Figura(speed), _podstawa(podstawa), _wysokosc(wysokosc)
{
}

bool Trojkat::czyKliknieta(float x, float y)
{
	return abs(x - _x) <= 1.0* _podstawa/ 2 && abs(y - _y) <= 1.0*_wysokosc / 2;
	
}


