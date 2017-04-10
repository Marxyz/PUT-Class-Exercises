#include "cFigura.h"


cFigura::cFigura() : R(0.0), G(0.0), B(0.0), alpha(0.0), CFizyka()
{
	this->x = 0;
	this->y = 0;
}

cFigura::cFigura(double x, double y) : R(0.0), G(0.0), B(0.0), alpha(0.0), CFizyka()
{
	this->x = x;
	this->y = y;
}

void cFigura::Rotate(double alpha)
{
	this->alfa_g += alpha;
	this->alfa_v += alpha;
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