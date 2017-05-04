#include "Drawable.h"



Drawable::Drawable()
{
	this->x = 0;
	this->y = 0;
	this->perimeter.xa = 0;
	this->perimeter.ya = 0;
	this->perimeter.xb = 0;
	this->perimeter.yb = 0;
	this->v = 0;
	this->vAlpha = 0;
	this->visible = true;
	this->time = GetTickCount();
}

void Drawable::MoveUp()
{
	this->x -= .1*cos(alpha*3.14 / 180);
	this->y -= .1*sin(alpha*3.14 / 180);
}

void Drawable::MoveDown()
{
	this->x += .1*cos(alpha*3.14 / 180);
	this->y += .1*sin(alpha*3.14 / 180);
}


void Drawable::MoveTo(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Drawable::Rotate(float alpha)
{
	this->alpha += alpha;
	if (this->alpha >360)
	{
		this->alpha = (int)this->alpha % 360;
	}
}

void Drawable::RotateTo(float alpha)
{
	this->alpha = alpha;
}


Drawable::~Drawable()
{
}
