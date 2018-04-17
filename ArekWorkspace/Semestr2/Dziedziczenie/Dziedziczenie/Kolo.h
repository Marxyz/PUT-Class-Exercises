#pragma once
#include "Figura.h"

class Kolo : public Figura
{

	double _radius;
public:
	Kolo(double radius,double speed);

	void Draw() override;

	bool czyKliknieta(float x, float y) override;
};

