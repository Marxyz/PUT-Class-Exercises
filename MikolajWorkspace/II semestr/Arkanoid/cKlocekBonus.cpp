#include "cKlocekBonus.h"



cKlocekBonus::cKlocekBonus(float x, float y):cKlocek(x,y)
{
	this->v = (rand() % 20 / 10000.0);
	this->R = 0;
	this->G = 0;
	this->B = 0;
}

void cKlocekBonus::Odbicie(float alpha)
{
	cKlocek::Odbicie(alpha);
}


cKlocekBonus::~cKlocekBonus()
{
}
