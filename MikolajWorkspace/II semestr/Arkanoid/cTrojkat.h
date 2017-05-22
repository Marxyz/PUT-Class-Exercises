#pragma once
#include "cFigura.h"
class cTrojkat :
	public cFigura
{
	double podstawa, wysokosc;
public:
	cTrojkat();
	cTrojkat(float _x, float _y, double podstawa, double wysokosc);
	~cTrojkat();
	void Draw() override;
	bool IsActive(double x, double y) override;
};

