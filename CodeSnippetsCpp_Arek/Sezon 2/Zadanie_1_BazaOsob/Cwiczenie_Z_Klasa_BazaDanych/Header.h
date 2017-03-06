#pragma once
#include <list>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Osoba
{
private:
	//Pola
	string _imie;
	string _nazwisko;
	float _waga;
	float _wzrost;
	int _wiek;
public:
	//Metody
	void Wyswietl();
	void UstawWszystko(const string& imie, const string& nazwisko, int wiek, float waga, float wzrost);
	void UstawWiek(int wiek);
	int  ZwrocWiek();
	void PobierzDaneOdUzytkownika();
	string ZwrocImieNazwisko();
	void PobierzDaneDoOsoby(string daneWejscia);
	string OsobaToString();
	Osoba(); //Konstruktor Domyœlny
	Osoba(const string& imie, const string& nazwisko); //Konstruktor dodatkowy

};


class BazaOsob
{
private:
	vector<Osoba> _zbiorOsob;
public:
	BazaOsob();
	void DodajOsobe();
	void DodajOsobe(Osoba & os);
	bool UsunOsobe(const string& imie, const string& nazwisko);
	void WyswietlCalaListe();
	BazaOsob ListaWiekowa(int wiekMin, int wiekMax);
	Osoba ZnajdzOsobe(const string& imie, const string& nazwisko);
	void WczytajZPliku(const string& nazwaPliku);
	void ZapiszDoPliku(const string& nazwaPliku);
	int RozmiarBazy();

};
