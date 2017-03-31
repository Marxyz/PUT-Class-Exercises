#include "Figura.h"
#include <cstdlib>

double FRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}
void Figura::SetColor(double r, double g, double b)
{
	c_r = r;
	c_b = b;
	c_g = g;
}

void Figura::MoveLeft()
{
	this->_x -= _speed;
}

void Figura::MoveRight()
{
	this->_x += _speed;
}

void Figura::MoveUp()
{
	this->_y += _speed;
}

void Figura::MoveDown()
{
	this->_y -= _speed;
}


void Figura::Rotate(double dalpha)
{
	this->_alpha += dalpha;
	_alpha = int(_alpha) % 360;
}

Figura::Figura(double speed) :_x(0), _y(0), _alpha(0), _speed(speed)
{
	SetColor(FRand(0, 1), FRand(0, 1), FRand(0, 1));
}




void Figura::GoTo(double x, double y)
{
	_x = x;
	_y = y;
}
