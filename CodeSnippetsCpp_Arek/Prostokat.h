#pragma once
#include "Figura.h"
class Prostokat : public Figura
{
private:
	double _dlugosc;
	double _wysokosc;
	double _speed;
	double _alpha;



public:

	void Draw();
	void Rotate(double dalpha);
	void MoveTo(int x, int y);
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void SetColor(double r, double g, double b);
	Prostokat(int dlugosc, int wysokosc, double speed);
	Prostokat();
};