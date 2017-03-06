#include <iostream>
#include "cOsoba.h"
#include <cstdlib>


int main() {

	bazaOsob baza;
	while (1) {
		system("cls");
		cout << "Witaj, co chcesz zrobic:" << endl << "1. Wyswietl baze." << endl << "2. Dodaj osobe." << endl << "3. Usun osobe" << endl;
		cout << "4. Wyeksportuj liste" << endl << "5. Utworz liste z przedzialem wiekowym" << endl;

		int wybor;
		cin >> wybor;
		while (!cin) {
			system("cls");
			cout << "Nie wprowadziles poprawnego numeru operacji." << endl;
			cin.clear();
			cin.ignore(20, '\n');
			cin >> wybor;
		}
		switch (wybor) {
		case 1: {
			system("cls");
			baza.wyswietl();
			_getch();
			break;
		}
		case 2: {
			system("cls");
			baza.dodajOsobe();
			break;
		}
		case 3: {
			system("cls");
			string imie, nazwisko;
			cout << "Podaj imie i nazwisko osoby do zpacyfikowania" << endl;
			cin >> imie >> nazwisko;
			baza.usunOsobe(imie, nazwisko);
			break;
		}
		case 4: {
			system("cls");
			string nazwa;
			cout << "Podaj nazwe pliku do wyeksporowania" << endl;
			baza.zapisz(nazwa);
			break;
		}
		case 5: {
			system("cls");
			int min, max;
			cout << "Podaj minimalny i maksymalny wiek." << endl;
			cin >> min >> max;
			bazaOsob baza2 = baza.listaWiekowa(min, max);
			baza2.wyswietl();
			_getch();
			break;
		}
		default: {
			system("cls");
			cout << "Podano zly numer operacji. Sproboj ponownie!" << endl;
			_getch();
			break;
		}
		}

		
	}

	return 0;
}