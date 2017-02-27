#include "Header.h"


Osoba::Osoba() //Domyœlny
{

}

Osoba::Osoba(const string& imie, const string& nazwisko)
{
	_imie = imie;
	_nazwisko = nazwisko;
}

void Osoba::UstawWiek(int wiek)
{
	if (wiek > 0 )
	{
		_wiek = wiek;
	}
};

string Osoba::SczytajImieNazwisko()
{
	return _imie + _nazwisko;
}

void Osoba::UstawWszystko(const string& imie, const string& nazwisko, int wiek, float waga, float wzrost)
{
	_imie = imie;
	_nazwisko = nazwisko;
	_wiek = wiek;
	_waga = waga;
	_wzrost = wzrost;
};

string Osoba::ToString()
{
	char tab[1000];
	sprintf(tab, "%s;%s%d;%f;%f\n", _imie, _nazwisko, _wiek, _waga, _wzrost);
	return tab;
}