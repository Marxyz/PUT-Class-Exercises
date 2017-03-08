#pragma once
#include <vector>
using namespace std;

class Macierz
{
	int _iloscKolumn;
	int _iloscRzedow;
	vector<vector<int>> _zasob;

	
	Macierz PomnozMacierz(Macierz& macierzB);
	
	void UstawRozmiarWypelnZerem(int wysokosc, int szerokosc);

	

public:
	Macierz OdejmijMacierz(Macierz & macierzB);
	Macierz DodajMacierz(Macierz& macierzB);
	Macierz PomnozMacierz(int skalar);
	void PobierzMacierz();
	void Wyswietl();
	Macierz();
	Macierz(int wysokosc, int szerokosc);

};
