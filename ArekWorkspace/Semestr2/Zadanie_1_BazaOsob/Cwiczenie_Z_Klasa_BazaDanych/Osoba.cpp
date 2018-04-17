
#include "OsobaIBaza.h"
#include <iostream>


Osoba::Osoba() :_imie(""), _nazwisko(""), _wiek(0)
{

	//Domyœlny

}

Osoba::Osoba(const string& imie, const string& nazwisko) :_imie(imie), _nazwisko(nazwisko), _wiek(0)
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

	this->Wyswietl();
}

string Osoba::ZwrocImieNazwisko()
{
	return _imie + _nazwisko;
}

void Osoba::PobierzDaneDoOsoby(string daneWejscia)
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




// BAZA OSOB


bool PredykatTeSameImieNazwisko(Osoba &osoba, string imie, string nazwisko)
{
	return osoba.ZwrocImieNazwisko() == imie + nazwisko;
}


BazaOsob::BazaOsob()
{
}

void BazaOsob::DodajOsobe()
{
	//Dodaj osobe z danych konsolowych podawanych prze uzytkownika
	Osoba o;
	o.PobierzDaneOdUzytkownika();
	_zbiorOsob.push_back(o);
}

void BazaOsob::DodajOsobe(Osoba& os)
{
	//Dodaj obiekt osoba
	_zbiorOsob.push_back(os);
}

bool BazaOsob::UsunOsobe(const string& imie, const string& nazwisko)
{
	for (auto i = _zbiorOsob.begin(); i != _zbiorOsob.end();)
	{
		if (i->ZwrocImieNazwisko() == imie + nazwisko)
		{
			i = _zbiorOsob.erase(i);
			return true;
		}
		++i;
	}

	return false;
}

void BazaOsob::WyswietlCalaListe()
{
	if (_zbiorOsob.size() == 0)
	{
		cout << "Baza jest aktualnie pusta, zaimportuj plik lub dodaj osobe." << endl << endl;
	}
	else
	{
		for (auto i = _zbiorOsob.begin(); i != _zbiorOsob.end(); ++i)
		{
			i->Wyswietl();
		}
	}

}

BazaOsob BazaOsob::ListaWiekowa(int wiekMin, int wiekMax)
{
	BazaOsob Baza_Wiek;
	for (Osoba el : _zbiorOsob)
	{
		if (el.ZwrocWiek() >= wiekMin && el.ZwrocWiek() <= wiekMax)
		{
			Baza_Wiek.DodajOsobe(el);
		}
	}
	return Baza_Wiek;
}

Osoba BazaOsob::ZnajdzOsobe(const string& imie, const string& nazwisko)
{
	Osoba tmp;
	for (auto i = _zbiorOsob.begin(); i != _zbiorOsob.end(); ++i)
	{
		if (PredykatTeSameImieNazwisko(*i, imie, nazwisko))
		{
			tmp = *i;
		}
	}
	return tmp;
}

void BazaOsob::WczytajZPliku(const string& nazwaPliku)
{
	fstream plik;
	plik.open(nazwaPliku, ios::in);
	if (plik.good())
	{
		while (!plik.eof())
		{
			Osoba tmp;
			string linia;
			getline(plik, linia);
			if (linia.length() > 0)
			{
				tmp.PobierzDaneDoOsoby(linia);
				_zbiorOsob.push_back(tmp);
			}

		}
		plik.close();
		WyswietlCalaListe();
	}
	else
	{
		cout << "Blad odczytu." << endl;
	}
}

void BazaOsob::ZapiszDoPliku(const string& sciezka)
{
	fstream plik;
	plik.open(sciezka, ios::out);
	if (plik.good())
	{
		for (auto i = _zbiorOsob.begin(); i != _zbiorOsob.end(); ++i)
		{
			plik << i->OsobaToString();
		}

		plik.close();
	}
	else
	{
		cout << "Blad odczytu." << endl;
	}

}

int BazaOsob::RozmiarBazy()
{
	return _zbiorOsob.size();
}

