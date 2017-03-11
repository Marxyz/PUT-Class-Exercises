#pragma once
#include <vector>
using namespace std;

class Macierz
{
	int _iloscKolumn;
	int _iloscRzedow;
	vector<vector<double>> _zasob;

	Macierz OdejmijMacierz(const Macierz & macierzB);
	Macierz DodajMacierz(const Macierz& macierzB);
	Macierz PomnozMacierz(const double skalar);
	void UstawRozmiarWypelnZerem(int wysokosc, int szerokosc);
	Macierz PomnozMacierz(const Macierz& macierzB);
	void MacierzFromString(string input);
	Macierz Poteguj(const int n);
	Macierz StworzDopelnienie(int wiersz, int kolumna);
	Macierz Podziel(Macierz& macierzB);
	
public:
	
	Macierz operator^(const int n);
	Macierz operator+(const Macierz& macierzB);
	Macierz operator-(const Macierz& macierzB);
	Macierz operator*(const Macierz& macierzB);
	Macierz operator*(const double skalar);
	Macierz operator/(Macierz & macierzB);


	Macierz StworzMacierzOdwrotna();
	Macierz StworzMacierzTransponowana();
	
	string ToString();
	
	int ObliczWyznacznik();

	void PobierzMacierz();
	void Wyswietl();

	Macierz();
	Macierz(int wysokosc, int szerokosc);
	Macierz(const string input);
};

Macierz operator*(const double& lhs,  Macierz& rhs);
