#pragma once
#include "Figura.h"
class Prostokat : public Figura
{
private:

	double _dlugosc;
	double _wysokosc;

public:

	bool czyKliknieta(float x, float y) override;
	void Draw() override;
	Prostokat(int dlugosc, int wysokosc, double speed);
	Prostokat();
};