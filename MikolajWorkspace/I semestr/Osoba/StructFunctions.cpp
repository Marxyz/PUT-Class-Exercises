#include "StructFunctions.h"

void WyswietlOsobe(Osoba  osoba){
	cout << osoba.imie << " " << osoba.nazwisko << endl;
	cout << osoba.wiek<<endl<<osoba.waga << endl << osoba.wiek << endl << osoba.wzrost << endl;
}

Osoba WczytajOsobe(){
	Osoba o;
	cin >> o.imie >> o.nazwisko >> o.waga >> o.wiek >> o.wzrost;
	return o;
}

void DodajOsobe(list<Osoba>&lista, Osoba &o){
	lista.push_back(o);
}

void DodajOsobe(list<Osoba>&lista){
	lista.push_back(WczytajOsobe());
}

void UsunOsobe(list<Osoba>&lista){
	string imie, nazwisko;
	cin >> imie;
	cin >> nazwisko;
	for (auto itr = lista.begin(); itr != lista.end();){
		if (itr->imie == imie && itr->nazwisko == nazwisko){
			itr = lista.erase(itr);  
		}
		else itr++;
	}
}

bool Starszy(const Osoba&a, const Osoba&b){
	if (a.wiek > b.wiek){
		return true;
	}
	else return false;
}

void SortujWiekiem(list<Osoba>&lista){
	lista.sort(Starszy);
}