#include "cFigura.h"


cFigura::cFigura():x(0.0), y(0.0), R(0.0), G(0.0), B(0.0), alpha(0.0)
{
}

cFigura::cFigura(double x, double y): R(0.0), G(0.0), B(0.0), alpha(0.0)
{
	this->x = x;
	this->y = y;
}

void cFigura::Rotate(double alpha)
{
	this->alpha += alpha;
}

void cFigura::Move(double x, double y)
{
	this->x += x;
	this->y += y;
}


void cFigura::MoveTo(double x, double y)
{
	this->x = x;
	this->y = y;
}

void cFigura::SetColor(double r, double g, double b)
{
	this->R = r;
	this->G = g;
	this->B = b;
}


cFigura::~cFigura()
{
}
