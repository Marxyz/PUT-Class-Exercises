#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Macierz
{
	int _iloscKolumn;
	int _iloscRzedow;
	vector<vector<int>> _zasob;

	Macierz DodajMacierz(Macierz macierzB);
	Macierz PomnozMacierz(Macierz macierzB);
	void PobierzMacierz();
	void Wyswietl();

	

public:

	Macierz();
	Macierz(int wysokosc, int szerokosc);

};