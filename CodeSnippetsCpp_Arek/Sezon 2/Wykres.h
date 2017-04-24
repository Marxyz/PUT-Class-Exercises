#pragma once
#include <vector>
#include <string>
using namespace std;
struct Punkt
{
	float x;
	float y;
};

class Wykres
{
private:

	vector<Punkt> _Zbior_Punktow;
	void Dodaj_Punkt(Punkt punkt);
	bool Sczytaj(string nazwa);
	bool SczytajLinie(string linia);

	float _xmin;
	float _xmax;
	float _ymin;
	float _ymax;

public:

	void Zoom();
	void Fit();
	void Pan();
	void Rysuj();
	Wykres(string NazwaPliku);
};

