#include "Func.h"

Osoba::Osoba(){};
Osoba::Osoba(const string &ximie, const string &xnazwisko){};
Osoba::Osoba(const string &imie, const string &nazwisko, int wiek, double masa, double wzrost){};
void Osoba::Wyswietl(){};
void Osoba::Pobierz(){};
int Osoba::Wiek(){};
void Osoba::UstawWszystko(const string &imie, const string &nazwisko, int wiek, double masa, double wzrost){};
void Osoba::UstawWiek(int wiek){
	xwiek = wiek;
}
string Osoba::ImieiNazwisko(){
	return ximie + " " + xnazwisko;
}
string Osoba::ToString(){
	char tab[1000];
};
void Osoba::FromString(const string &wejscie){};