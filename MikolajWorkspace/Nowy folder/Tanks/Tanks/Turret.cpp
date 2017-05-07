#include "Turret.h"



Turret::Turret()
{
}
Turret::Turret(float x, float y): Drawable() {
	this->x = x;
	this->y = y;
	this->width = 2;
	this->height = 2;
	this->alpha = 0;
	this->barrel = 4.5;
	this->SetPerimeter(-width / 2, -height / 2, width / 2, height / 2);
}
void Turret::Draw()
{
	glPushMatrix();
	glTranslated(x, y, 0.0);
	glRotated(alpha, 0, 0, 1);
	glPushMatrix();
	glTranslated(width / 2, 0, 0);
	glColor3d(0.070, 0.317, 0.019);
	glBegin(GL_POLYGON);
	{
		glVertex2f(-width / 2.0, -height / 2.0);
		glVertex2f(width / 2, -height / 2.0);
		glVertex2f(width / 2, height / 2);
		glVertex2f(-width / 2, height / 2);
	}
	glEnd();
	glColor3d(0.121, 0.243, 0.098);
	glBegin(GL_POLYGON);
	{
		glVertex2f(-width / 2 - barrel, (-height / 2) / 3);
		glVertex2f(-width / 2, (-height / 2) / 3);
		glVertex2f(-width / 2, (height / 2) / 3);
		glVertex2f(-width / 2 - barrel, (height / 2) / 3);
	}
	glEnd();
	glPopMatrix();
	glPopMatrix();
}


Turret::~Turret()
{
}
