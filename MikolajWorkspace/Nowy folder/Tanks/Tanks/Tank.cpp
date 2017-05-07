#include "Tank.h"
#include <iostream>


Tank::Tank(float x, float y): turret(x,y), Drawable()
{
	this->x = x;
	this->y = y;
	this->width = 5;
	this->height = 3;
	/*this->alpha = 0;
	this->vAlpha = 0;
	this->visible = true;*/
	//turret = Turret(0, 0);
	this->SetPerimeter(-width / 2, -height / 2, width / 2, height / 2);
}

void Tank::MoveUp()
{
	Drawable::MoveUp();
	this->turret.SetY(this->GetY());
	this->turret.SetX(this->GetX());
}

void Tank::MoveDown()
{
	Drawable::MoveDown();
	this->turret.SetX(this->GetX());
	this->turret.SetY(this->GetY());
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

	//glRotated(-alpha, 0, 0, 1);
	
	glPopMatrix();
	this->turret.Draw();
	
	

}

void Tank::RotateTurret(float angle)
{
	this->turret.RotateTo(angle);
}


void Tank::Shoot()
{
	this->ammo--;
}


Tank::~Tank()
{
}
