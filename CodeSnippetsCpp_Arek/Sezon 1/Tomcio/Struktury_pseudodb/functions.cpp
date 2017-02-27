#include "functions.h"

void Dodaj_Osobe(list<sOsoba>& Lista_Osob, sOsoba osoba)
{
	Lista_Osob.push_front(osoba);
}

bool Usun_Osobe(list<sOsoba>& Lista_Osob, string imie, string nazwisko)
{
	for (auto itr = Lista_Osob.begin(); itr != Lista_Osob.end(); itr++)
	{
		if (itr->imie == imie && itr->nazwisko == nazwisko)
		{
			Lista_Osob.erase(itr);
			return true;
		}
	}
	return false;

}

void Wyswietl_Osobe(sOsoba osoba)
{
	cout << "Imie: ";
	cout << osoba.imie << "   ";
	cout << "Nazwisko: ";
	cout << osoba.nazwisko << "   ";
	cout << "Wiek: ";
	cout << osoba.wiek << "   ";
	cout << "Wzrost: ";
	cout << osoba.wzrost << "   ";
	cout << "Waga: ";
	cout << osoba.waga<< endl;

}
sOsoba Pobierz_Osobe()
{
	string imie, nazwisko;
	int age, wzrost;
	double weight;
	cout << "Podaj imie:" << endl;
	cin >> imie;
	cout << "Podaj nazwisko:" << endl;
	cin >> nazwisko;
	cout << "Podaj wiek:" << endl;
	cin >> age;
	cout << "Podaj wzrost:" << endl;
	cin >> wzrost;
	cout << "Podaj wage:" << endl;
	cin >> weight;

	sOsoba result = { imie, nazwisko, age, weight, wzrost };
	return result;

}

void Pokaz_Aktualne_Dane(list<sOsoba> & Lista_Osob)
{
	for (auto itr = Lista_Osob.begin(); itr != Lista_Osob.end(); itr++)
	{
		Wyswietl_Osobe(*itr);
	}
}

sOsoba Znajdz_Najwyzszego(list<sOsoba>& Lista_Osob)
{
	sOsoba najwyzszy = Lista_Osob.front();
	for (auto itr = Lista_Osob.begin(); itr != Lista_Osob.end(); itr++)
	{
		if (itr->wzrost > najwyzszy.wzrost)
		{
			najwyzszy = *itr;
		}
	}
	return najwyzszy;
}
bool predicate(sOsoba p1, sOsoba p2)
{
	return p1.wiek < p2.wiek;
}

void Posortuj_Wzgledem_Wieku(list<sOsoba>& Lista_Osob)
{
	Lista_Osob.sort(predicate);
}

double Oblicz_Srednia_Wage(list<sOsoba>& Lista_Osob)
{
	double suma_wag = 0;
	for (auto itr = Lista_Osob.begin(); itr != Lista_Osob.end(); itr++)
	{
		suma_wag += itr->waga;
	}
	
	return 1.0*suma_wag/Lista_Osob.size();
}

