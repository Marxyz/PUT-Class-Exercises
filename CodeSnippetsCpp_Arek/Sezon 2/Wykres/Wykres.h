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

	bool SczytajLinie(string linia);
	void UstawMinimalneWartosci();

public:
	float XMin;
	float XMax;
	float YMin;
	float YMax;

	void Dodaj_Punkt(const Punkt& punkt);
	void Sczytaj(string nazwaPliku);

	void Rysuj();

	Wykres(string NazwaPliku);
};