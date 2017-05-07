#pragma once
#include "Figura.h"
class Prostokat : public Figura
{
protected:

	double _dlugosc;
	double _wysokosc;

public:

	bool czyKliknieta(float x, float y) override;
	void Draw() override;
	Prostokat(double dlugosc, double wysokosc, double speed);
	Prostokat();
};