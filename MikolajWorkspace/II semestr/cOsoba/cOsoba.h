
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
	cOsoba(const string& imie, const string& nazwisko); //< konstruktor dwuargumentowy zawieraj�cy imi� i nazwisko
	void pobierz(); //< metoda pobiera dane osoby od u�ytkownika
	void wyswietl(); //< metoda wy�wietla dane osoby
	int wiek(); //< getter pola m_wiek
	void ustawWszystko(const string& imie, const string& nazwisko, int wiek); //< setter dla ��cznego ustawiania wszystkich atrybut�w klasy
	void ustawWiek(int wiek); //< setter dla wieku
	string imieNazwisko(); //< getter dla napisu zawieraj�cego imie nazwisko
	string toString();//< generuje lini� tekstu z polami odzielonymi �rednikami
	void fromString(const string& tekst);//< wczytuje lini� tekstu z polami oddzielonymi �rednikami (tak� jak generuje metoda toString) i przypisuje warto�ci
};


class bazaOsob
{
	//pola klasy
	vector<cOsoba> m_tablicaOsob;

public:
	//metody klasy
	void dodajOsobe();//< dodaje now� osobe do bazy
	void dodajOsobe(cOsoba & osoba);
	void wyswietl();//< wy�wietla dane oosby na konsoli
	bool usunOsobe(const string& imie, const string& nazwisko); //<usuwa os�b� na podstawie imienia i nazwiska
	cOsoba znajdzOsobe(const string& imie, const string& nazwisko); //< wyszujuje osob� w bazie po imieniu i nazwisku

	bazaOsob listaWiekowa(int wiekMin, int wiekMax); //< generuje list� os�b w danym zakresie wiekowym
	void wczytaj(const string& nazwaPliku); //< wczytuje dane z pliku tekstowego typu csv
	void zapisz(const string& nazwaPliku); //< zapisuje dane do pliku tekstowego typu csv
};

#endif /* OSOBY_H_ */
