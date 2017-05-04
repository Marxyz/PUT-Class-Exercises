#pragma once
#include "Drawable.h"
class Turret :
	public Drawable
{
private:
	float width, height;
	float barrel;
public:
	Turret();
	Turret(float x, float y);
	void Draw() override;
	~Turret();
};

