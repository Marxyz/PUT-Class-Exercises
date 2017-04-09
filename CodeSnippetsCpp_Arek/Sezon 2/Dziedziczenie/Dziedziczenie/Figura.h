#pragma once
#include "../../../../../../Desktop/Arkanoid-master/cFizyka.h"

class Figura : public CFizyka
{

protected:

	/*float _x, _y;*/
	double c_r, c_g, c_b;
	double _alpha;
	double _speed;

public:

	void GoTo(double x, double y);
	void SetColor(double r, double g, double b);
	void MoveLeft();
	void MoveRight();
	void MoveDown();
	void MoveUp();
	void Rotate(double dalpha);

	virtual bool czyKliknieta(float x, float y) = 0;
	virtual void Draw() = 0;

	Figura(double speed);
};

