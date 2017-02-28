#include "Header.h"
using namespace std;

int main(int argc, char* argv[])
{
	Osoba o, o2;
	BazaOsob baza;

	//Testowe
	o.UstawWszystko("Arkadiusz", "Marks", 21, 80, 179.6);
	o2.UstawWszystko("Agnieszka", "Gebala", 21, 50.1, 162);	
	baza.DodajOsobe(o);
	baza.DodajOsobe(o2);
	


	BazaOsob listaWiekowa;
	string imie, nazwisko, nazwaPlikuImport, nazwaPlikuExport;
	int maxWiek, minWiek;



	while (true)
	{
		cout << "Polecenie: 'n' - dodawanie nowej osoby. " << endl;
		cout << "Polecenie: 'a' - wyswietlenie calej listy osob. " << endl;
		cout << "Polecenie: 'r' - usuniecie osoby o podanym imieniu i nazwisku. " << endl;
		cout << "Polecenie: 'e' - eksport bazy osob do pliku o podanej nazwie. " << endl;
		cout << "Polecenie: 'i' - import listy osob z pliku o podanej nazwie. " << endl;
		cout << "Polecenie: 'b' - stworzenie listy z ograniczonym przedzialem wiekowym. " << endl;
		
		//TODO: wyœwietliæ menu
		char wybor = getchar();
		
		
		switch (wybor)
		{

		case 'n': baza.DodajOsobe(); // dodaje now¹ osobê do bazy z danych wprowadzonych z klawiatury
			break;
		case 'a':baza.WyswietlCalaListe();
			break;
		case 'r':
			cout << "Podaj imie :" << endl;
			cin >> imie;
			cout << "Podaj nazwisko" << endl;
			cin >> nazwisko;
			baza.UsunOsobe(imie, nazwisko);
			break;
		case 'e':
			cout << "Podaj nazwe pliku do exportu" << endl;
			cin >> nazwaPlikuExport;
			baza.ZapiszDoPliku(nazwaPlikuExport);
			break;
		case 'i':
			cout << "Podaj nazwe pliku do importu" << endl;
			cin >> nazwaPlikuImport;
			baza.WczytajZPliku(nazwaPlikuImport);
			break;
		case 'b':
			cout << "Podaj minimalny przedzial wiekowy" << endl;
			cin >> minWiek;
			cout << "Podaj maksymalny przedzial wiekowy" << endl;
			cin >> maxWiek;
			listaWiekowa = baza.ListaWiekowa(minWiek, maxWiek);
			listaWiekowa.WyswietlCalaListe();
			break;
		default:
			cout << "Polecenie niepoprawne" << endl;
		}
	}
}
