#pragma once
#include "cFigura.h"
class cProstokat :
	public cFigura
{
protected:
	double width, height;
public:
	cProstokat();
	cProstokat(float x, float y, double width, double height);
	void Draw() override;
	bool IsActive(double x, double y) override;

	~cProstokat();
};

