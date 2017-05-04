#include "Tank.h"



Tank::Tank(): turret(0,0)
{
	this->x = 0;
	this->y = 0;
	this->width = 5;
	this->height = 3;
	this->alpha = 0;
	//turret = Turret(0, 0);
}

void Tank::Draw()
{
	glPushMatrix();
	glTranslated(x, y, 0);
	glRotated(alpha, 0, 0, 1);
	
	glColor3d(0.145, 0.513, 0.066);
	glBegin(GL_POLYGON);
	{
		glVertex3d(-width / 2, -height / 2, 0);
		glVertex3d(width / 2, -height / 2, 0);
		glVertex3d(width / 2, height / 2, 0);
		glVertex3d(-width / 2, height / 2, 0);

	}
	glEnd();
	this->turret.Draw();
	glPopMatrix();

}

void Tank::RotateTurret(float angle)
{
	this->turret.RotateTo(angle);
}


Tank::~Tank()
{
}
