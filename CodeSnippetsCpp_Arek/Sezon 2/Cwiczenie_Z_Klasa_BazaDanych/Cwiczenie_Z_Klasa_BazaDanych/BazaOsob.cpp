#include "Header.h"



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
	for (auto i = _zbiorOsob.begin(); i != _zbiorOsob.end(); ++i)
	{
		i->Wyswietl();
	}
}

BazaOsob BazaOsob::ListaWiekowa(int wiekMin, int wiekMax)
{
	BazaOsob Baza_Wiek;
	for (Osoba el: _zbiorOsob)
	{
		if (el.ZwrocWiek() >= wiekMin && el.ZwrocWiek() <= wiekMax )
		{
			Baza_Wiek.DodajOsobe(el);
		}
	}
	return Baza_Wiek;
}

Osoba BazaOsob::ZnajdzOsobe(const string& imie, const string& nazwisko)
{
	for (auto i = _zbiorOsob.begin(); i != _zbiorOsob.end(); ++i)
	{
		if (PredykatTeSameImieNazwisko(*i,imie,nazwisko))
		{
			return *i;
		}
	}
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
