#include "functions.h"

int main()
{
	list<sOsoba> lista_osob;
	sOsoba p1 = { "Kevin","Sam w domu",12,45,154 };
	sOsoba p2 = { "Abraham", "Lincoln",2017 - 1809,70,186 };
	sOsoba p3 = { "Krolik","Bugs",2017 - 1938,20,120 };
	sOsoba p4 = { "Michal","Jordan",2017 - 1963,98,204 };
	sOsoba p5 = Pobierz_Osobe();

	Dodaj_Osobe(lista_osob, p1);
	Dodaj_Osobe(lista_osob, p2);
	Dodaj_Osobe(lista_osob, p3);
	Dodaj_Osobe(lista_osob, p4);
	Dodaj_Osobe(lista_osob, p5);



	cout << "Najwyzszy :" << endl;
	Wyswietl_Osobe(Znajdz_Najwyzszego(lista_osob));
	
	
	Posortuj_Wzgledem_Wieku(lista_osob);

	cout << "______________________" << endl;


	Pokaz_Aktualne_Dane(lista_osob);

	cout << "Srednia wagi: " << Oblicz_Srednia_Wage(lista_osob) << endl;
	return 0;
}
