#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <vector>

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
		void Pobierz();
		void UstawWszystko(const string& imie, const string& nazwisko, int wiek, float waga, float wzrost);
		void UstawWiek(int wiek);
		int  SczytajWiek();
		string SczytajImieNazwisko();
		void SczytajInputDanych(const string& daneWejscia);
		string ToString();
		Osoba(); //Konstruktor Domyœlny
		Osoba(const string& imie, const string& nazwisko); //Konstruktor dodatkowy

};


class BazaOsob
{
	private:
		vector<Osoba> _zbiorOsob;
	public:
		void DodajOsobe();
		bool UsunOsobe(const string& imie, const string& nazwisko);
		void WyswietlCalaListe();
		BazaOsob ListaWiekowa(int wiekMin, int wiekMax);
		Osoba ZnajdzOsobe(const string& imie, const string& nazwisko);
		void WczytajZPliku(const string& nazwaPliku);
		void ZapiszDoPliku(const string& nazwaPliku);
		int RozmiarPliku();

};



#endif