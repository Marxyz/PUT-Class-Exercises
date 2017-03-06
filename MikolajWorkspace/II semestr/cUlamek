#include "cUlamek.h"
cUlamek::cUlamek() :_licznik(0), _mianownik(1){}
cUlamek::cUlamek(int a, int b) :_licznik(a){
	if (b != 0){
		_mianownik = b;
	}
}

cUlamek cUlamek::operator+(int a) const{
	cUlamek wynik;
	wynik._licznik = _licznik+a*_mianownik;
	wynik._mianownik = _mianownik;
	return wynik;
}

cUlamek cUlamek::operator+(const cUlamek&u) const{
	cUlamek wynik;
	wynik._licznik = _licznik*u._mianownik + u._licznik*_mianownik;
	wynik._mianownik = _mianownik*u._mianownik;
	return wynik;
}

void cUlamek::setLicznik(int a){
	_licznik = a;
}

cUlamek cUlamek::operator*(int a) const{
	cUlamek wynik;
	wynik._licznik = _licznik*a;
	wynik._mianownik = _mianownik;
}

cUlamek operator*(int x, const cUlamek&u){
	return u*x;
	
}

cUlamek cUlamek::operator=(const cUlamek&u){
	this->_licznik = u._licznik;
	this->_mianownik = u._mianownik;
	return *this;
}
cUlamek::operator double(){

}

//TODO: klasa cMacierz, tablica dwuwymiarowa, operacje mnozenia dodawania, wysiwetlania, pobierania, wyznacnzik macierzy, macierz zerwao, jedynkowa




