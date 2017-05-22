#pragma once
#include "cProstokat.h"

class cKlocek : public cProstokat{
protected:
	int punkty;
	int odpornosc;
public:
	cKlocek(float x, float y);
	int GetPunkty();
	virtual void Odbicie(float alpha);
	int GetOdpornosc() { return odpornosc; }
	~cKlocek();
};