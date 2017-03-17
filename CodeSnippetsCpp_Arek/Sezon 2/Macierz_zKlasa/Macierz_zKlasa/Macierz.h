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

public:

	Macierz operator ^ (const int n);
	Macierz operator + (const Macierz& macierzB);
	Macierz operator - (const Macierz& macierzB);
	Macierz operator * (const Macierz& macierzB);
	Macierz operator * (const double skalar);
	Macierz operator / (Macierz & macierzB);
	friend ostream& operator << (ostream& strumien, Macierz& m);
	friend istream& operator >> (istream& strumien, Macierz& m);

	Macierz StworzMacierzOdwrotna();
	Macierz StworzMacierzTransponowana();

	const string ToString();

	int ObliczWyznacznik();

	Macierz();
	Macierz(int wysokosc, int szerokosc);
	Macierz(const string input);
};

Macierz operator*(const double& lhs, Macierz& rhs);