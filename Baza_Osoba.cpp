#include "Header.h"
#include <fstream>

BazaOsob::BazaOsob(){} // Konstruktor Domyœlny


void BazaOsob::DodajOsobe()
{
	Osoba o;
	o.Pobierz();
	_zbiorOsob.push_back(o);
}

void BazaOsob::ZapiszDoPliku(const string& sciezka)
{
	fstream plik;
	plik.open(sciezka, ios::app);
	for (auto i = _zbiorOsob.begin(); i != _zbiorOsob.end() ; i++)
	{
		plik << i->ToString;
	}
}