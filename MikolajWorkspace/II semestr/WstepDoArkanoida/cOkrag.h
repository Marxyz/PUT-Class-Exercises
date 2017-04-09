#pragma once
#include "cFigura.h"
class cOkrag :
	public cFigura
{
	double r;
public:
	cOkrag();
	cOkrag(float x, float y,double r);
	~cOkrag();
	void Draw() override;
	bool IsActive(double x, double y) override;
};

