#pragma once
#include "cProstokat.h"

class cKlocek : public cProstokat{
protected:
	int punkty;
	int odpornosc;
public:
	cKlocek();
	int GetPunkty();
	void Odbicie(float alpha);
	~cKlocek();
};