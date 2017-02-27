#ifndef FUNC_H
#define FUNC_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Osoba{
private:
	string ximie;
	string xnazwisko;
	int xwiek;
	double xmasa;
	double xwzrost;

public:
	Osoba();
	Osoba(const string &ximie, const string &xnazwisko);
	Osoba(const string &imie, const string &nazwisko, int wiek, double masa, double wzrost);
	void Wyswietl();
	void Pobierz();
	int Wiek();
	void UstawWszystko(const string &imie, const string &nazwisko, int wiek, double masa, double wzrost);
	void UstawWiek(int wiek);
	string ImieiNazwisko();
	string ToString();
	void FromString(const string &wejscie);
};

class BazaOsob{
private:
	vector<Osoba> listaOsob;
public:
	BazaOsob();
	void DodajOsobe();
	bool UsunOsobe(const string &imie, const string &nazwisko);
	void Wyswietl();
	BazaOsob ListaWiekowa(int wiekStart, int wiekMax);
	Osoba Znajdz(const string &imie, const string &nazwisko);
	void Wczytaj(const string &nazwaPliku);
	void Zapisz(const string &nazwaPliku);
	int Rozmiar();
};
#endif