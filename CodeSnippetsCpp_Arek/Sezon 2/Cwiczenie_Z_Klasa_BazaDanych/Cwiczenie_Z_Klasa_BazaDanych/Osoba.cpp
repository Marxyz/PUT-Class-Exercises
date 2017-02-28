#include "Header.h"


Osoba::Osoba():_imie(""),_nazwisko(""),_wiek(0)
{

	//Domyœlny

}

Osoba::Osoba(const string& imie, const string& nazwisko):_imie(imie),_nazwisko(nazwisko),_wiek(0)
{
}

void Osoba::UstawWiek(int wiek)
{
	if (wiek > 0)
	{
		_wiek = wiek;
	}
}

int Osoba::ZwrocWiek()
{
	return _wiek;
};


void Osoba::PobierzDaneOdUzytkownika()
{
	cout << "Podaj Imie " << endl;
	cin >> _imie;
	cout << "Podaj nazwisko" << endl;
	cin >> _nazwisko;
	cout << "Podaj wiek " << endl;
	cin >> _wiek;
	cout << "Podaj wage" << endl;
	cin >> _waga;
	cout << "Podaj wzrost" << endl;
	cin >> _wzrost;

	Wyswietl();
}

string Osoba::ZwrocImieNazwisko()
{
	return _imie + _nazwisko;
}

void Osoba::PobierzDaneDoOsoby( string daneWejscia)
{
	int pos = daneWejscia.find(';');
	_imie = daneWejscia.substr(0, pos);
	daneWejscia = daneWejscia.substr(pos + 1);
	pos = daneWejscia.find(';');
	_nazwisko = daneWejscia.substr(0, pos);
	daneWejscia = daneWejscia.substr(pos + 1);
	pos = daneWejscia.find(';');
	_wiek = stoi(daneWejscia.substr(0, pos));
	daneWejscia = daneWejscia.substr(pos + 1);
	pos = daneWejscia.find(';');
	_waga = stof(daneWejscia.substr(0, pos));
	daneWejscia = daneWejscia.substr(pos + 1);
	pos = daneWejscia.find(';');
	_wzrost = stof(daneWejscia.substr(0, pos));
}


void Osoba::Wyswietl()
{
	cout << "Imie: " << _imie << endl;
	cout << "Nazwisko: " << _nazwisko << endl;
	cout << "Wiek: " << _wiek << endl;
	cout << "Waga: " << _waga << endl;
	cout << "Wzrost: " << _wzrost << endl;
	cout << endl;
}

void Osoba::UstawWszystko(const string& imie, const string& nazwisko, int wiek, float waga, float wzrost)
{
	_imie = imie;
	_nazwisko = nazwisko;
	_wiek = wiek;
	_waga = waga;
	_wzrost = wzrost;
};

string Osoba::OsobaToString()
{
	char tab[1000];
	sprintf(tab, "%s;%s;%d;%f;%f;\n", _imie.c_str(), _nazwisko.c_str(), _wiek, _waga, _wzrost);
	return tab;
}