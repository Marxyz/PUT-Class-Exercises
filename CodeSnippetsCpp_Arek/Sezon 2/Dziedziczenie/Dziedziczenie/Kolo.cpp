#include "Kolo.h"
#include <GL/freeglut.h>
#include <math.h>
#include <cstdlib>


Kolo::Kolo(double radius, double speed) :Figura(speed), _radius(radius)
{
}

void Kolo::Draw()
{
	glPushMatrix();
	glTranslated(_x, _y, 0);
	glRotated(_alpha, 0, 0, 1);
	glColor3d(c_r, c_g, c_b);
	glBegin(GL_POLYGON);
	{
		for (int angle = 0; angle < 365; angle++)
		{
			double angle_radians = 1.0* angle * 3.14159 / 180;
			double x = _radius * cos(angle_radians);
			double y = _radius * sin(angle_radians);
			glVertex3d(x, y, 0);
		}
	}
	glEnd();
	glPopMatrix();

}

bool Kolo::czyKliknieta(float x, float y)
{
	return pow(abs(x - _x), 2) + pow(abs(y - _y), 2) <= _radius*_radius;


}