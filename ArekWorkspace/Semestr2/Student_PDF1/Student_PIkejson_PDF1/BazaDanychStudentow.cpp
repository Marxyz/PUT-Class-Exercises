#include "Header.h"
#include <iostream>

// Ta referencja jest diabelnie wazna
RocznikStudentow& BazaDanychStudentow::ZnajdzRocznik(int rocznik)
{
	RocznikStudentow tmp;
	for (auto itr = this->_zbiorRocznikow.begin(); itr != this->_zbiorRocznikow.end(); ++itr)
	{
		if (itr->ZwrocRocznik() == rocznik)
		{
			return *itr;
		}
		
	}
	return tmp;
}

int BazaDanychStudentow::ZwrocOgolnaLiczbeStudentow()
{
	return _ogolnaIloscStudentow;
}

void BazaDanychStudentow::DodajRocznikStudentow(RocznikStudentow &rocznik)
{
	int buffor, ilosc;
	_zbiorRocznikow.push_back(rocznik);
	buffor = rocznik.ZwrocIloscStudentowNaRoku();
	ilosc = this->ZwrocOgolnaLiczbeStudentow();
	_ogolnaIloscStudentow = ilosc + buffor;
}

void BazaDanychStudentow::InformacjaORoczniku(int rocznik, ostream& strumien)
{
	this->ZnajdzRocznik(rocznik).InformacjaORoczniku(strumien);
}

//TODO::
void BazaDanychStudentow::PosortujRocznikWgIndexow(int rocznik)
{
	this->ZnajdzRocznik(rocznik).PosortujStudentowWgIndexow();
}

void BazaDanychStudentow::PosortujRocznikWgNazwisk(int rocznik)
{
	this->ZnajdzRocznik(rocznik).PosortujStudentowWgNazwisk();
}

BazaDanychStudentow::BazaDanychStudentow(): _ogolnaIloscStudentow(0)
{
}
