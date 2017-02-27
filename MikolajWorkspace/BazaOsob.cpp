#include "Func.h"

BazaOsob();
void BazaOsob::DodajOsobe(){
	Osoba o;
	o.Pobierz();
	listaOsob.push_back(o);
};
bool UsunOsobe(const string &imie, const string &nazwisko);
void Wyswietl();
BazaOsob ListaWiekowa(int wiekStart, int wiekMax);
Osoba Znajdz(const string &imie, const string &nazwisko);
void Wczytaj(const string &nazwaPliku);
void Zapisz(const string &nazwaPliku){
	ofstream plik(nazwaPliku);
};
int Rozmiar();