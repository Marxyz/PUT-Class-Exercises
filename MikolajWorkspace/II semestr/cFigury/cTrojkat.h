#pragma once
#include "cFigura.h"
class cTrojkat :
	public cFigura
{
	double podstawa, wysokosc;
public:
	cTrojkat();
	~cTrojkat();
	void Draw() override;
	bool IsActive(double x, double y) override;
};

