#include "cSegment.h"

cSegment::cSegment(): width(.1), height(.1), x(0), y(0), R(0), G(0),B(0),alpha(0)
{
}

cSegment::cSegment(float a, float b): cSegment()
{
	this->width = a;
	this->height = b;
}

void cSegment::SetX(float a)
{
	this->x = a;
}

void cSegment::SetY(float a)
{
	this->y = a;
}

void cSegment::SetAlpha(float a)
{
	this->alpha = alpha;
}

float cSegment::GetX()
{
	return this->x;
}

float cSegment::GetY()
{
	return this->y;
}

float cSegment::GetAlpha()
{
	return this->alpha;
}

void cSegment::Move(float a, float b)
{
	this->x += a;
	this->y += b;
}

void cSegment::MoveTo(float a, float b)
{
	this->x = a;
	this->y = b;
}

void cSegment::Draw()
{
	glPushMatrix();

	glTranslated(x, y, 0.0);
	glRotated(alpha, 0.0, 0.0, 1.0);
	glColor3f(R, G, B);
	glBegin(GL_POLYGON);
	glVertex3f(-width/2, 0, 0);
	glVertex3f(width/2, 0, 0);
	glVertex3f(width/2, height, 0);
	glVertex3f(-width/2, height, 0);
	glEnd();
	glTranslated(0.0, height, 0.0);
}

void cSegment::Rotate(float alpha)
{
	this->alpha += alpha;
	if(this->alpha >360)
	{
		//float tmp = this->alpha;
		this->alpha = (int)this->alpha%360;
	}
}

void cSegment::RotateTo(float alpha)
{
	this->alpha = alpha;
}

void cSegment::SetColor(float a, float b, float c)
{
	this->R = a;
	this->G = b;
	this->B = c;
}
