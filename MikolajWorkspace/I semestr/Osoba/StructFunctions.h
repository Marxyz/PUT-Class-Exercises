#ifndef STRUCTFUNCTIONS_H
#define STRUCTFUNCTIONS_H

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <conio.h>
#include <cstdlib>

using namespace std;

struct Osoba {
	string imie;
	string nazwisko;
	int wiek;
	double wzrost;
	double waga;
};

void WyswietlOsobe(Osoba  osoba);
void DodajOsobe(list<Osoba>&lista, Osoba &o);
void DodajOsobe(list<Osoba>&lista);
void UsunOsobe(list<Osoba>&lista);
void SortujWiekiem(list<Osoba>&lista);
bool Starszy(const Osoba&a, const Osoba&b);
#endif