#pragma once
#include "GL/freeglut.h"
#include <cmath>
#include "cFizyka.h"

class cFigura : public CFizyka
{
protected:
	double R, G, B;
	double alpha;
public:
	cFigura();
	cFigura(double x, double y);

	void Rotate(double alpha);
	void Move(double x, double y);
	void MoveTo(double x, double y);
	void SetColor(double r, double g, double b);

	virtual void Draw() = 0;
	virtual bool IsActive(double x, double y) = 0;

	~cFigura();
};

