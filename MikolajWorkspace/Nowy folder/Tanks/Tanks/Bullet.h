#pragma once
#include "Drawable.h"
class Bullet :
	public Drawable
{
private: 
	float radius;
public:
	Bullet(float x, float y);
	~Bullet();
	void Draw() override;
};

