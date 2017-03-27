#pragma once
class Prostokat
{
private:
	double _dlugosc;
	double _wysokosc;
	double _x_sr, _y_sr;
	double c_r, c_g, c_b;
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

