#pragma once
#include "cFigura.h"
class cProstokat :
	public cFigura
{
	double width, height;
public:
	cProstokat();
	void Draw() override;
	bool IsActive(double x, double y) override;

	~cProstokat();
};

