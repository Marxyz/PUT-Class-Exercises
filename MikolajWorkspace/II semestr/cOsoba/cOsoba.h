
#ifndef OSOBY_H_
#define OSOBY_H_
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <conio.h>

using namespace std;

class cOsoba {
private:
	//pola klasy
	string m_imie;
	string m_nazwisko;
	int m_wiek; //< wiek w latach
public:
	//metody klasy
	cOsoba(); //< konstruktor domyslny
	cOsoba(const string& imie, const string& nazwisko); //< konstruktor dwuargumentowy zawieraj¹cy imiê i nazwisko
	void pobierz(); //< metoda pobiera dane osoby od u¿ytkownika
	void wyswietl(); //< metoda wyœwietla dane osoby
	int wiek(); //< getter pola m_wiek
	void ustawWszystko(const string& imie, const string& nazwisko, int wiek); //< setter dla ³¹cznego ustawiania wszystkich atrybutów klasy
	void ustawWiek(int wiek); //< setter dla wieku
	string imieNazwisko(); //< getter dla napisu zawieraj¹cego imie nazwisko
	string toString();//< generuje liniê tekstu z polami odzielonymi œrednikami
	void fromString(const string& tekst);//< wczytuje liniê tekstu z polami oddzielonymi œrednikami (tak¹ jak generuje metoda toString) i przypisuje wartoœci
};


class bazaOsob
{
	//pola klasy
	vector<cOsoba> m_tablicaOsob;

public:
	//metody klasy
	void dodajOsobe();//< dodaje now¹ osobe do bazy
	void dodajOsobe(cOsoba & osoba);
	void wyswietl();//< wyœwietla dane oosby na konsoli
	bool usunOsobe(const string& imie, const string& nazwisko); //<usuwa os¹bê na podstawie imienia i nazwiska
	cOsoba znajdzOsobe(const string& imie, const string& nazwisko); //< wyszujuje osobê w bazie po imieniu i nazwisku

	bazaOsob listaWiekowa(int wiekMin, int wiekMax); //< generuje listê osób w danym zakresie wiekowym
	void wczytaj(const string& nazwaPliku); //< wczytuje dane z pliku tekstowego typu csv
	void zapisz(const string& nazwaPliku); //< zapisuje dane do pliku tekstowego typu csv
};

#endif /* OSOBY_H_ */
