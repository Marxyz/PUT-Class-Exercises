#include <iostream>
#define NDEBUG
#include <GL/freeglut.h>
#include <vector>
#include <ctime>
#include "Prostokat.h"
#include <cstdlib>
#include "Robot.h"

double FRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}
void Prostokat::Draw()
{

	glPushMatrix();
	// TODO
	// test functions below (glTranslated, glRotated, glColor3d) - what happens when you change their arguments?
	// does their order change the result?
	glTranslated(_x_sr, _y_sr, 0);
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

void Prostokat::Rotate(double dalpha)
{
	_alpha += dalpha;
	if (_alpha > 360)
	{
		_alpha = 0;
	}
}

void Prostokat::MoveTo(int x, int y)
{

}

void Prostokat::MoveLeft()
{
	this->_x_sr -= _speed;
}

void Prostokat::MoveRight()
{
	this->_x_sr += _speed;
}

void Prostokat::MoveUp()
{
	this->_y_sr += _speed;
}

void Prostokat::MoveDown()
{
	this->_y_sr -= _speed;
}


void Prostokat::SetColor(double r, double g, double b)
{
	this->c_r = r;
	this->c_g = g;
	this->c_b = b;
}

Prostokat::Prostokat(int dlugosc, int wysokosc, double speed) : _dlugosc(dlugosc), _wysokosc(wysokosc), _x_sr(0), _y_sr(0), _speed(speed), _alpha(0)
{
	this->c_r = FRand(0, 1);
	this->c_g = FRand(0, 1);
	this->c_b = FRand(0, 1);

}

Prostokat::Prostokat()
{

}

