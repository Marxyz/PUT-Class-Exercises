#pragma once
#define PI 3.14159
typedef struct sGranica
{
	float xa; //minimalna wartosc x
	float ya; //minimalna wartosc y
	float xb; //maskymalna wartosc x
	float yb;//maskymalna wartosc y
} sGranica;/*granice okreslaja lewy gorny naroznik (xa,ya) i prawy dolny (xb,yb) */


class CFizyka
{
protected:
	int czas; //czas ostatniej aktualizacji
	sGranica granica; //granice obiektu
	float x, y; //polozenie srodka masy
	float v;//predkosc
	float alfa_v;//kierunek wektora predkosci w [stopniach]
	float g; //grawitacja
	float alfa_g;//kierunek wektora grawitacji

public:
	CFizyka();
	float ZwracajX() { return float(x); }
	float ZwracajY() { return float(y); }
	void UstawX(float _x) { x = (int)_x; }
	void UstawY(float _y) { y = (int)_y; }
	void Odbicie(float alfa_n); //odbicie od sciany charakteryzowanej za pomoca normalnej alfa_n
	void Aktualizuj(int czas_aktualny);//zmienia polozenie obiektu na podstawie aktualnego czasu
	void setPredkosc(float _v, float _alfa_v); //ustawia poczatkowa predkosc
	void setFizyka(float _g, float _alfa_g); //ustawia poczatkowe przyspieszenie
	void setGeometria(float _x, float _y, float _xa, float _ya, float _xb, float _yb);
	virtual int Kolizja(CFizyka& X); //wykrywanie kolizji z innym obiektem (funkcja przekazuje 1 gdy jest kolizja 0 gdy brak)
	int IsInRect(float _x, float _y, const CFizyka& X);//wykrywa czy dany punkt (_x,_y) znajduje sie wewnatrz pewnego kwadratu
	float odleglosc(float _x, float _y, float _xa, float _ya, float _xb, float _yb);//wyznacza odleglosc od pewnej prostej przechodzacej przez 2 punkty
	virtual float ZnajdzNormalna(const CFizyka& X);//znajduje normalna boku ktory jest najblizej srodka obiektu (wynikiem funkcji jest orientacja normalnej);
	void Reset(); //resetuje czas
	virtual ~CFizyka();

};
	


