#include "cOsoba.h"
#include <fstream>

cOsoba::cOsoba() :m_imie(""), m_nazwisko(""), m_wiek(0) //konstruktor domyslny z list a inicjalizacyjn¹
{
	//	m_imie=""jan;
	//	m_nazwisko="kowalski";
	//	m_wiek=30;
}
cOsoba::cOsoba(const string& imie, const string& nazwisko) :m_imie(imie), m_nazwisko(nazwisko), m_wiek(0) {

}


void cOsoba::pobierz() {
	cout << "Podaj imie: ";
	cin >> m_imie;
	cout << "Podaj nazwisko: ";
	cin >> m_nazwisko;
	cout << "Podaj wiek: ";
	cin >> m_wiek;

	cout << "Wprowadziles: ";
	wyswietl();
	_getch();
}
void cOsoba::wyswietl() {
	cout << "Imie: " << m_imie << endl << "Nazwisko: " << m_nazwisko << endl<<"Wiek: "<<m_wiek<<endl;
}
int cOsoba::wiek() {
	return m_wiek;
}


void cOsoba::ustawWszystko(const string& imie, const string& nazwisko,
	int wiek) {
	m_imie = imie;
	m_nazwisko = nazwisko;
	if (wiek >= 0)
		m_wiek = wiek;
}

void cOsoba::ustawWiek(int wiek) {
	if (wiek >= 0)
		m_wiek = wiek;
}

string cOsoba::imieNazwisko() {
	return m_imie + " " + m_nazwisko;
}

string cOsoba::toString() {
	char tab[1000];
	sprintf(tab, "%s;%s;%d\r\n", m_imie.c_str(), m_nazwisko.c_str(), m_wiek);
	return tab;
}

void cOsoba::fromString(const string& tekst) {
	if (tekst != "") {
		stringstream ss(tekst);
		string wiek;
		getline(ss, m_imie, ';');
		getline(ss, m_nazwisko, ';');
		getline(ss, wiek);
		m_wiek = stoi(wiek);
	}
	
}

void bazaOsob::dodajOsobe() {
	cOsoba o;
	o.pobierz();
	m_tablicaOsob.push_back(o);
}

void bazaOsob::dodajOsobe(cOsoba &osoba) {
	m_tablicaOsob.push_back(osoba);
}

bool bazaOsob::usunOsobe(const string& imie, const string& nazwisko) {
	for (auto itr = m_tablicaOsob.begin(); itr != m_tablicaOsob.end();) {
		if (itr->imieNazwisko() == imie + " " + nazwisko) {
			itr = m_tablicaOsob.erase(itr);
			return true;
		}
		else itr++;
	}
	return false;
}


cOsoba bazaOsob::znajdzOsobe(const string& imie, const string& nazwisko) {
	for (auto itr = m_tablicaOsob.begin(); itr != m_tablicaOsob.end(); itr++) {
		if (itr->imieNazwisko() == imie + " " + nazwisko) {
			return *itr;
		}
	}
}

bazaOsob bazaOsob::listaWiekowa(int wiekMin, int wiekMax) {
	bazaOsob baza;
	for (auto itr = m_tablicaOsob.begin(); itr != m_tablicaOsob.end(); itr++) {
		if (itr->wiek() >= wiekMin && itr->wiek() <= wiekMax) {
			baza.dodajOsobe(*itr);
		}
	}
	return baza;
}

void bazaOsob::wczytaj(const string& nazwaPliku) {
	ifstream plik(nazwaPliku);
	while (!plik.eof()) {
			string line;
			cOsoba osoba;
			getline(plik, line);
			if (line != "") {
				osoba.fromString(line);
				dodajOsobe(osoba);
			}
		}
		
	plik.close();
}

void bazaOsob::wyswietl() {
	for (auto& el : m_tablicaOsob)
	{
		el.wyswietl();
	}
}

void bazaOsob::zapisz(const string& nazwaPliku) {
	ofstream plik(nazwaPliku);
	for (auto& el : m_tablicaOsob)
	{
		plik << el.toString();
	}
	plik.close();
}