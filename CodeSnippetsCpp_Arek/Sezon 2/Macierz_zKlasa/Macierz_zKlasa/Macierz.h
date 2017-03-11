#pragma once
#include <vector>
using namespace std;

class Macierz
{
	int _iloscKolumn;
	int _iloscRzedow;
	vector<vector<int>> _zasob;

	Macierz OdejmijMacierz(const Macierz & macierzB);
	Macierz DodajMacierz(const Macierz& macierzB);
	Macierz PomnozMacierz(int skalar);
	void UstawRozmiarWypelnZerem(int wysokosc, int szerokosc);
	Macierz PomnozMacierz(const Macierz& macierzB);
	void MacierzFromString(string input);
	Macierz Poteguj(const int n);
	

public:
	Macierz StworzDopelnienie(int wiersz, int kolumna);
	int ObliczWyznacznik();
	Macierz operator^(const int n);
	Macierz operator+(const Macierz& macierzB);
	Macierz operator-(const Macierz& macierzB);
	Macierz operator*(const Macierz& macierzB);
	Macierz operator*(const int skalar);

	string ToString();
	void PobierzMacierz();
	void Wyswietl();

	Macierz();
	Macierz(int wysokosc, int szerokosc);
	Macierz(const string input);
};

Macierz operator*(const int& lhs,  Macierz& rhs);
