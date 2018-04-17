#include <windows.h>
#include <math.h>
#include "Fizyka.h"
#include <iostream>
//odbicie tlyko w plaszczyznie xy pamietac, najwazniejsze to jest ta kolizja!

Fizyka::Fizyka()
{
	//obiekt staly
	g = 0.0;
	alfa_g = 0.0;
	v = 0.0;
	alfa_v = 0.0;
	//ustawia domyslna obwiednie obiektu
	granica.xa = -1.0;
	granica.ya = -1.0;

	granica.xb = 1.0;
	granica.yb = 1.0;
	Reset();
	this->widoczny = 1;
	_x = 0;
	_y = 0;
}


bool Fizyka::ZwracajWidoczny()
{
	return this->widoczny;
}

void Fizyka::Odbicie(float alfa_n) //odbicie od sciany charakteryzowanej za pomoca normalnej alfa_n
{
	//prawo odbicia "kat padania rowny katowi odbicia (pod warunkiem, ze obiekt wnika do wnetrza)
	if (fabs(alfa_n - alfa_v) > 90.0) {
		alfa_v = alfa_n - (180.0 + alfa_v - alfa_n);
	}

}

void Fizyka::Aktualizuj(float czas_aktualny) //zmienia polozenie obiektu na podstawie aktualnego czasu
{

	float delta_t = czas_aktualny - czas, v_x, v_y;
	if (delta_t>1000) delta_t = 100;//dla przerwy dluzszej niz 1s nie przeprowadzana jest aktualizacja
	v_x = v*cos(alfa_v / 180.0*PI);
	v_y = v*sin(alfa_v / 180.0*PI);
	//aktualizacja polozenia
	_x = _x + v_x*delta_t + 0.5*g*cos(alfa_g / 180.0*PI)*delta_t*delta_t;
	_y = _y + v_y*delta_t + 0.5*g*sin(alfa_g / 180.0*PI)*delta_t*delta_t;

	//aktualizacja predkosci
	v_x = v_x + g*cos(alfa_g / 180.0*PI)*delta_t;
	v_y = v_y + g*sin(alfa_g / 180.0*PI)*delta_t;
	//wypadkowa predkosc
	v = sqrt(v_x*v_x + v_y*v_y);
	//kierunek predkosci
	alfa_v = atan2(v_y, v_x)*180.0 / PI;

	czas += delta_t;
}

void Fizyka::setPredkosc(float _v, float _alfa_v) //ustawia poczatkowa predkosc
{
	v = _v;
	alfa_v = _alfa_v;
	Reset();
}

void Fizyka::setFizyka(float _g, float _alfa_g) //ustawia poczatkowe przyspieszenie
{
	g = _g;
	alfa_g = _alfa_g;
	Reset();
}

void Fizyka::setGeometria(float _x, float _y, float _xa, float _ya, float _xb, float _yb)
{
	this->_x = _x;
	this->_y = _y;
	granica.xa = _xa;
	granica.xb = _xb;
	granica.ya = _ya;
	granica.yb = _yb;
	Reset();
}

int Fizyka::Kolizja(Fizyka& X) //wykrywanie kolizji z innym obiektem (funkcja przekazuje 1 gdy jest kolizja 0 gdy brak)
{
	//jesli wystepuje kolizja to przynajmniej jeden z wierzcholkow musi zawierac sie wewnatrz
	//sprawdzenie czy ktorys z wierzcholkow obiektu nie zawiera sie w obiekcie sprawdzanym
	int kolizja = 0;
	if (X.widoczny != 0)
	{

		if (IsInRect(_x + granica.xa, _y + granica.ya, X) == 1) kolizja = 1;
		else if (IsInRect(_x + granica.xa, _y + granica.yb, X) == 1) kolizja = 1;
		else if (IsInRect(_x + granica.xb, _y + granica.yb, X) == 1) kolizja = 1;
		else if (IsInRect(_x + granica.xb, _y + granica.ya, X) == 1) kolizja = 1;
		//odworcenie sprawdzania 
		else if (IsInRect(X._x + X.granica.xa, X._y + X.granica.ya, *this) == 1) kolizja = 1;
		else if (IsInRect(X._x + X.granica.xa, X._y + X.granica.yb, *this) == 1) kolizja = 1;
		else if (IsInRect(X._x + X.granica.xb, X._y + X.granica.yb, *this) == 1) kolizja = 1;
		else if (IsInRect(X._x + X.granica.xb, X._y + X.granica.ya, *this) == 1) kolizja = 1;

		//obsluga kolizji
		if (kolizja)
		{
			//znalezienie boku od ktorego nastapi odbicie
			float alfa_n = ZnajdzNormalna(X);
			Odbicie(alfa_n);
			float kat = (alfa_n>0) ? alfa_n - 180 : alfa_n + 180;
			if (kat == 0) kat = 180;
			X.Odbicie(kat);
		}
	}
	return kolizja;
}

int Fizyka::IsInRect(float _x, float _y, const Fizyka& X)//wykrywa czy dany punkt (_x,_y) znajduje sie wewnatrz pewnego kwadratu
{
	if (((_x < X._x + X.granica.xb) && (_x > X._x + X.granica.xa)) && ((_y < X._y + X.granica.yb) && (_y > X._y + X.granica.ya)))
		return 1;
	else return 0;
}

float Fizyka::odleglosc(float _x, float _y, float _xa, float _ya, float _xb, float _yb)//wyznacza odleglosc od pewnej prostej przechodzacej przez 2 punkty
{
	//rownanie prostej pzrechodzacej pzrez 2 punkty: y=Ax+B
	float d;
	if (_xb != _xa)
	{
		float A = (_yb - _ya) / (_xb - _xa);
		float B = _ya - A * _xa;
		//wyznaczenie odleglosci:
		d = fabs(A*_x - _y + B) / sqrt(A*A + 1.0);
	}
	else
		d = fabs(_x - _xb);
	return d;
}


float Fizyka::ZnajdzNormalna(const Fizyka& X)//znajduje normalna boku ktory jest najblizej srodka obiektu (wynikiem funkcji jest orientacja normalnej);
{
	float tab[4];//tablica zawierajaca odleglosci srodka obiektu od bokow, przyjmuje sie ze odbicie nastepuje od boku lezacego najblizej srodka obiektu
	int min_idx = 0;
	tab[0] = odleglosc(_x, _y, X._x + X.granica.xa, X._y + X.granica.ya, X._x + X.granica.xa, X._y + X.granica.yb);
	tab[1] = odleglosc(_x, _y, X._x + X.granica.xa, X._y + X.granica.yb, X._x + X.granica.xb, X._y + X.granica.yb);
	tab[2] = odleglosc(_x, _y, X._x + X.granica.xb, X._y + X.granica.yb, X._x + X.granica.xb, X._y + X.granica.ya);
	tab[3] = odleglosc(_x, _y, X._x + X.granica.xb, X._y + X.granica.ya, X._x + X.granica.xa, X._y + X.granica.ya);

	//poszukiwanie minimalnej wartosci odleglosci
	for (int i = 1; i<4; i++)
	{
		if (tab[i] < tab[min_idx]) min_idx = i;
	}
		

	//wyznaczenie normalnych najblizej lezacego boku, (dla aktualnej wersji zawsze leza wzdloz osi X lub Y)
	switch (min_idx) //do modyfikacji gdy beda obrócone
	{
	case 0: return 180.0;
	case 1: return 90.0;
	case 2: return 0.0;
	case 3: return -90.0;
	default: return 180;
	}

	return 180;
}

void Fizyka::Reset() //resetuje czas
{
	czas = GetTickCount();
}


