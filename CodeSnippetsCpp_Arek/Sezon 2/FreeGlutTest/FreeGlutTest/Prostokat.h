#pragma once
/*class Prostokat
{


// Globalny prostokat, metody dzialajace nanim
// Globalny vector<Prostokat> tab; w kotrym po iteracji robi sie draw,
// wcisniecie klawisza n dodaje nowy prostokat
// d - usuwanie
// przesuwanie kazdego z nich
// globalne current id - numer aktywnego prostokata. tab[current].move();
// wsad - operujace na aktualnym elemencie
// +-, zwieksza i zmniejsza current o 1


};*/



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
	~Prostokat();
};

