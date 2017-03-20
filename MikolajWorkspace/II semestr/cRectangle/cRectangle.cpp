#include "cRectangle.h"
#include <cstdlib>
#include <ctime>



cRectangle::cRectangle():height(1.0), width(1.0), x(0.0), y(0.0), alpha(0.0)
{
	srand(time(NULL));
	this->R = (rand() % 1000) / 1000.0;
	this->G = (rand() % 1000) / 1000.0;
	this->B = (rand() % 1000) / 1000.0;
}

cRectangle::cRectangle(float a, float b): height(a), width(b),x(0.0), y(0.0), alpha(0.0), R(0.0), G(0.0), B(0.0)
{
	srand(time(NULL));
	this->R = (rand() % 1000) / 1000.0;
	this->G = (rand() % 1000) / 1000.0;
	this->B = (rand() % 1000) / 1000.0;
}

void cRectangle::Move(float a, float b)
{
	this->x += a;
	this->y += b;
}

void cRectangle::MoveTo(float a, float b)
{
	this->x = a;
	this->y = b;
}

void cRectangle::Draw()
{
	glPushMatrix();
	
	glTranslated(x, y, 0.0);
	glRotated(alpha, 0.0, 0.0, 1.0);
	glColor3f(R, G, B);
	
	glBegin(GL_POLYGON);
	glVertex3f(-width / 2, -height / 2, 0);
	glVertex3f(width / 2, -height / 2, 0);
	glVertex3f(width / 2, height / 2, 0);
	glVertex3f(-width / 2, height / 2, 0);
	glEnd();
	
	glPopMatrix();

}

void cRectangle::Rotate(float alpha)
{
	this->alpha += alpha;
}

void cRectangle::SetColor(float r, float g, float b)
{
	this->R = r;
	this->G = g;
	this->B = b;
}

void cRectangle::Resize(float a, float b)
{
	this->height += a;
	this->width += b;
}


cRectangle::~cRectangle()
{
}
