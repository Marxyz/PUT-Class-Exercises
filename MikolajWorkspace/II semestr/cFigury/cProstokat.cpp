#include "cProstokat.h"



cProstokat::cProstokat():width(.2), height(.2)
{
}

void cProstokat::Draw()
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

bool cProstokat::IsActive(double x, double y)
{
	return abs(this->x - x) <= (width / 2) && abs(this->y - y) <= height / 2;
}


cProstokat::~cProstokat()
{
}
