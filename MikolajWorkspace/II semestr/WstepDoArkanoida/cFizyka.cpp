#include <windows.h>
#include <math.h>
#include "cFizyka.h"
#include <iostream>


CFizyka::CFizyka()
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
	this->widoczny = 1;
	Reset();
}
bool CFizyka::ZwracajWidoczny()
{
	return this->widoczny;
}

void CFizyka::Odbicie(float alfa_n) //odbicie od sciany charakteryzowanej za pomoca normalnej alfa_n
{
	//prawo odbicia "kat padania rowny katowi odbicia (pod warunkiem, ze obiekt wnika do wnetrza)
	if (fabs(alfa_n - alfa_v)>90.0)
		alfa_v = alfa_n - (180.0 + alfa_v - alfa_n);

}

void CFizyka::Aktualizuj(int czas_aktualny) //zmienia polozenie obiektu na podstawie aktualnego czasu
{

	float delta_t = czas_aktualny - czas, v_x, v_y;
	if (delta_t>1000) delta_t = 100;//dla przerwy dluzszej niz 1s nie przeprowadzana jest aktualizacja
	v_x = v*cos(alfa_v / 180.0*PI);
	v_y = v*sin(alfa_v / 180.0*PI);
	x = x + v_x*delta_t + 0.5*g*cos(alfa_g / 180.0*PI)*delta_t*delta_t;
	y = y + v_y*delta_t + 0.5*g*sin(alfa_g / 180.0*PI)*delta_t*delta_t;

	//aktualizacja predkosci
	v_x = v_x + g*cos(alfa_g / 180.0*PI)*delta_t;
	v_y = v_y + g*sin(alfa_g / 180.0*PI)*delta_t;
	//wypadkowa predkosc
	v = sqrt(v_x*v_x + v_y*v_y);
	//kierunek predkosci
	alfa_v = atan2(v_y, v_x)*180.0 / PI;

	czas += delta_t;
	//std::cout << alfa_v << std::endl;
}

void CFizyka::setPredkosc(float _v, float _alfa_v) //ustawia poczatkowa predkosc
{
	v = _v;
	alfa_v = _alfa_v;
	Reset();
}

void CFizyka::setFizyka(float _g, float _alfa_g) //ustawia poczatkowe przyspieszenie
{
	g = _g;
	alfa_g = _alfa_g;
	Reset();
}

void CFizyka::setGeometria(float _x, float _y, float _xa, float _ya, float _xb, float _yb)
{
	x = _x;
	y = _y;
	granica.xa = _xa;
	granica.xb = _xb;
	granica.ya = _ya;
	granica.yb = _yb;
	Reset();
}

int CFizyka::Kolizja(CFizyka& X) //wykrywanie kolizji z innym obiektem (funkcja przekazuje 1 gdy jest kolizja 0 gdy brak)
{
	//jesli wystepuje kolizja to przynajmniej jeden z wierzcholkow musi zawierac sie wewnatrz
	//sprawdzenie czy ktorys z wierzcholkow obiektu nie zawiera sie w obiekcie sprawdzanym
	int kolizja = 0;
	if (X.widoczny != 0)
	{
		if (IsInRect(x + granica.xa, y + granica.ya, X) == 1) kolizja = 1;
		else if (IsInRect(x + granica.xa, y + granica.yb, X) == 1) kolizja = 1;
		else if (IsInRect(x + granica.xb, y + granica.yb, X) == 1) kolizja = 1;
		else if (IsInRect(x + granica.xb, y + granica.ya, X) == 1) kolizja = 1;
		//odworcenie sprawdzania 
		else if (IsInRect(X.x + X.granica.xa, X.y + X.granica.ya, *this) == 1) kolizja = 1;
		else if (IsInRect(X.x + X.granica.xa, X.y + X.granica.yb, *this) == 1) kolizja = 1;
		else if (IsInRect(X.x + X.granica.xb, X.y + X.granica.yb, *this) == 1) kolizja = 1;
		else if (IsInRect(X.x + X.granica.xb, X.y + X.granica.ya, *this) == 1) kolizja = 1;

		//obsluga kolizji
		if (kolizja)
		{
			//znalezienie boku od ktorego nastapi odbicie
			float alfa_n = ZnajdzNormalna(X);
			Odbicie(alfa_n);
			float kat = (alfa_n > 0) ? alfa_n - 180 : alfa_n + 180;
			X.Odbicie(kat);
		}
	}

	return kolizja;
}

int CFizyka::IsInRect(float _x, float _y, const CFizyka& X)//wykrywa czy dany punkt (_x,_y) znajduje sie wewnatrz pewnego kwadratu
{
	if (((_x < X.x + X.granica.xb) && (_x > X.x + X.granica.xa)) && ((_y < X.y + X.granica.yb) && (_y > X.y + X.granica.ya)))
		return 1;
	else return 0;
}

float CFizyka::odleglosc(float _x, float _y, float _xa, float _ya, float _xb, float _yb)//wyznacza odleglosc od pewnej prostej przechodzacej przez 2 punkty
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


float CFizyka::ZnajdzNormalna(const CFizyka& X)//znajduje normalna boku ktory jest najblizej srodka obiektu (wynikiem funkcji jest orientacja normalnej);
{
	float tab[4];//tablica zawierajaca odleglosci srodka obiektu od bokow, przyjmuje sie ze odbicie nastepuje od boku lezacego najblizej srodka obiektu
	int min_idx = 0;
	tab[0] = odleglosc(x, y, X.x + X.granica.xa, X.y + X.granica.ya, X.x + X.granica.xa, X.y + X.granica.yb);
	tab[1] = odleglosc(x, y, X.x + X.granica.xa, X.y + X.granica.yb, X.x + X.granica.xb, X.y + X.granica.yb);
	tab[2] = odleglosc(x, y, X.x + X.granica.xb, X.y + X.granica.yb, X.x + X.granica.xb, X.y + X.granica.ya);
	tab[3] = odleglosc(x, y, X.x + X.granica.xb, X.y + X.granica.ya, X.x + X.granica.xa, X.y + X.granica.ya);

	//poszukiwanie minimalnej wartosci odleglosci
	for (int i = 1; i<4; i++)
		if (tab[i]<tab[min_idx]) min_idx = i;

	//wyznaczenie normalnych najblizej lezacego boku, (dla aktualnej wersji zawsze leza wzdloz osi X lub Y)
	switch (min_idx) //do modyfikacji gdy beda obr�cone
	{
	case 0: return 180.0;
	case 1: return 90.0;
	case 2: return 0.0;
	case 3: return -90.0;
	}

}

void CFizyka::Reset() //resetuje czas
{
	czas = GetTickCount();
}

CFizyka::~CFizyka()
{
}


