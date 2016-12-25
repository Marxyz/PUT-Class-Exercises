#include <iostream>
#include "StructFunctions.h"
using namespace std;

int main(){
	
	list<Osoba> listaOsob;
	
	Osoba o = { "Carl", "Johnson", 20, 190, 90 };
	listaOsob.push_back(o);
	//DodajOsobe(listaOsob);
	Osoba o1 = { "Albus", "Dumbledore", 24, 190, 90 };
	listaOsob.push_back(o1);
	Osoba o2 = { "Bill", "Gates", 21, 190, 90 };
	listaOsob.push_back(o2);
	Osoba o3 = { "OG", "Loc", 15, 190, 90 };
	listaOsob.push_back(o3);
	Osoba o4 = { "Adam", "Mickiewicz", 28, 190, 90 };
	listaOsob.push_back(o4);

	//UsunOsobe(listaOsob);
	SortujWiekiem(listaOsob);


	for (auto itr = listaOsob.begin(); itr != listaOsob.end(); itr++){
		WyswietlOsobe(*itr);
	}
	_getch();
	return 0;
}