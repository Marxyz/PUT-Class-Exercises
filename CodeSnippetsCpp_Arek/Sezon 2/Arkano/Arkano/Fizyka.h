#ifndef fizyka_h
#define fizyka_h
#define PI 3.14159


typedef struct sGranica
{
	float xa; //minimalna wartosc x 
	float ya; //minimalna wartosc y
	float xb; //maskymalna wartosc x
	float yb;//maskymalna wartosc y
} sGranica;/*granice okreslaja lewy dolny naroznik (xa,ya) i prawy górny (xb,yb) */


class Fizyka
{
protected:
	int czas; //czas ostatniej aktualizacji
	sGranica granica; //granice obiektu
	float _x, _y; //polozenie srodka masy
	float v;//predkosc
	float alfa_v;//kierunek wektora predkosci w [stopniach]
	float g; //grawitacja
	float alfa_g;//kierunek wektora grawitacji
	bool widoczny;
	

public:
	Fizyka();
	float ZwracajX() { return float(_x); }
	float ZwracajY() { return float(_y); }
	void UstawX(float _x) { _x = (int)_x; }
	void UstawY(float _y) { _y = (int)_y; }
	void Odbicie(float alfa_n); //odbicie od sciany charakteryzowanej za pomoca normalnej alfa_n
	void Aktualizuj(float czas_aktualny);//zmienia polozenie obiektu na podstawie aktualnego czasu
	void setPredkosc(float _v, float _alfa_v); //ustawia poczatkowa predkosc
	void setFizyka(float _g, float _alfa_g); //ustawia poczatkowe przyspieszenie
	void setGeometria(float _x, float _y, float _xa, float _ya, float _xb, float _yb);
	virtual int Kolizja(Fizyka& X); //wykrywanie kolizji z innym obiektem (funkcja przekazuje 1 gdy jest kolizja 0 gdy brak)
	int IsInRect(float _x, float _y, const Fizyka& X);//wykrywa czy dany punkt (_x,_y) znajduje sie wewnatrz pewnego kwadratu
	float odleglosc(float _x, float _y, float _xa, float _ya, float _xb, float _yb);//wyznacza odleglosc od pewnej prostej przechodzacej przez 2 punkty
	virtual float ZnajdzNormalna(const Fizyka& X);//znajduje normalna boku ktory jest najblizej srodka obiektu (wynikiem funkcji jest orientacja normalnej);
	void Reset(); //resetuje czas
	bool ZwracajWidoczny();
};

#endif
