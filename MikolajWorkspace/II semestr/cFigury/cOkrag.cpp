#include "cOkrag.h"



cOkrag::cOkrag(): r(.1)
{
}


cOkrag::~cOkrag()
{
}

void cOkrag::Draw()
{
	
	glPushMatrix();

	glTranslated(x, y, 0.0);
	glRotated(alpha, 0.0, 0.0, 1.0);
	glColor3f(R, G, B);

	glBegin(GL_POLYGON);
	for (float kat = 0;kat<360;kat += 5)
	{
		double x, y;
		x = r*cos(kat / 180 * 3.14);
		y = r*sin(kat / 180 * 3.14);
		glVertex2f(x, y);
	}
	glEnd();

	glPopMatrix();

}

bool cOkrag::IsActive(double x, double y)
{
	return pow((this->x - x), 2) + pow((this->y - y), 2) <=  pow(r, 2);
}
