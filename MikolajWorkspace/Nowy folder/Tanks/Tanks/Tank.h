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
	Tank(float x, float y);
	void MoveUp();
	void MoveDown();
	void Draw() override;
	void RotateTurret(float angle);
	void Shoot();
	float GetBarrel() { return this->turret.GetBarrel(); }
	float getTurretAlpha() { return this->turret.GetAlpha(); }
	float GetTurretX() { return this->turret.GetX(); }
	float GetTurretY() { return this->turret.GetY(); }
	~Tank();
};

