#pragma once
#include "Drawable.h"
#include "Turret.h"
#include "Bullet.h"
class Tank :
	public Drawable
{
private:
	Turret turret;
	float width, height;
public:
	int ammo;

public:
	Tank();
	void Draw() override;
	void RotateTurret(float angle);
	~Tank();
};

