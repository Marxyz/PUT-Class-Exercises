#pragma once
#include "cKlocek.h"
class cKlocekBonus :
	public cKlocek
{
protected:
	float v;
public:
	cKlocekBonus(float x, float y);
	void Odbicie(float alpha);
	float GetV() { return v; }
	~cKlocekBonus();
};

