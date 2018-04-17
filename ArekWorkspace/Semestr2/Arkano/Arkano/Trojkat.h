#pragma once
#include "Figura.h"
class Trojkat :public Figura
{
	double _podstawa;
	double _wysokosc;
public:

	void Draw() override;
	Trojkat();
	Trojkat(double wysokosc, double podstawa, double speed);
	bool czyKliknieta(float x, float y) override;
};

