
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

struct sOsoba
{
	string imie;
	string nazwisko;
	int wiek;
	double waga;
	int wzrost;
};

void Dodaj_Osobe(list<sOsoba>& Lista_Osob, sOsoba osoba);
bool Usun_Osobe(list<sOsoba>& Lista_Osob, string imie, string nazwisko);
void Wyswietl_Osobe(sOsoba osoba);
sOsoba Pobierz_Osobe();
void Pokaz_Aktualne_Dane(list<sOsoba> & Lista_Osob);
sOsoba Znajdz_Najwyzszego(list<sOsoba>& Lista_Osob);
void Posortuj_Wzgledem_Wieku(list<sOsoba>& Lista_Osob);
double Oblicz_Srednia_Wage(list<sOsoba>& Lista_Osob);
bool predicate(sOsoba p1, sOsoba p2);

#endif
