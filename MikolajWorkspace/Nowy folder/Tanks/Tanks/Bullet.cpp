#include "Bullet.h"



Bullet::Bullet(float x, float y): Drawable()
{
	this->x = x;
	this->y = y;
	this->radius = .3;
	this->SetPerimeter(-radius / 2, -radius / 2, radius / 2, radius / 2);
}


Bullet::~Bullet()
{
}

void Bullet::Draw()
{
	glPushMatrix();
	glTranslated(x, y, 0.0);
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
		for(int i = 0; i<365; i+=5)
		{
			float x, y;
			x = this->radius*cos(i / 180.0*3.141592);
			y = this->radius*sin(i / 180.0*3.141592);
			glVertex2f(x, y);
		}
	glEnd();
	glPopMatrix();
}
