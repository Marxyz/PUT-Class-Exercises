#include "Header.h"
#include <fstream>
#include <iostream>
#include <algorithm>


bool PredykatSortujNazwiskami( KartaStudenta & st1, KartaStudenta & st2 )
{
	if (st1.ZwrocNazwisko() < st2.ZwrocNazwisko())
		return true;
	return false;
}


bool PredykatSortujIndeksami(KartaStudenta & st1, KartaStudenta & st2)
{
	if (st1.ZwrocIndex() < st2.ZwrocIndex())
		return true;
	return false;
}


void RocznikStudentow::UstawRocznik(int rocznik)
{
	_rocznik = rocznik;
}

int RocznikStudentow::ZwrocIloscStudentowNaRoku()
{
	return _iloscStudentowNaRoku;
}

int RocznikStudentow::ZwrocRocznik()
{
	return _rocznik;
}

KartaStudenta& RocznikStudentow::ZnajdzStudenta(int index)
{
	KartaStudenta tmp;
	for (auto itr = _zbiorKartStudenckich.begin(); itr != _zbiorKartStudenckich.end(); ++itr)
	{
		if (itr->ZwrocIndex() == index)
		{
			return *itr;
		}
	}
	return tmp;
}

void RocznikStudentow::PosortujStudentowWgNazwisk()
{
	sort(_zbiorKartStudenckich.begin(), _zbiorKartStudenckich.end(), PredykatSortujNazwiskami);
	this->_zbiorKartStudenckich;
}


void RocznikStudentow::PosortujStudentowWgIndexow()
{
	sort(_zbiorKartStudenckich.begin(), _zbiorKartStudenckich.end(), PredykatSortujIndeksami);
}

void RocznikStudentow::InformacjaORoczniku(ostream& stream)
{
	stream << "ROCZNIK: " << _rocznik << endl;
	WydrukStudentow(stream);
}

void RocznikStudentow::WydrukStudentow(ostream& stream)
{
	for (auto itr = _zbiorKartStudenckich.begin(); itr != _zbiorKartStudenckich.end(); ++itr)
	{
		itr->WydrukStudenta(stream);
	}
}

void RocznikStudentow::SczytajPlikStudentow(const string& nazwaPliku)
{
	fstream plik;
	plik.open(nazwaPliku, ios::in);
	if (plik.good())
	{
		while (!plik.eof())
		{
			KartaStudenta tmp;
			string linia;
			getline(plik, linia);
			if (linia != "")
			{
				tmp.SczytajStudentaString(linia);
				this->DodajStudenta(tmp);
			}
			
		}
	}
	else { cout << "Plik niepoprawny." << endl; }
}

void RocznikStudentow::DodajStudenta(KartaStudenta& student)
{
	_zbiorKartStudenckich.push_back(student);
	_iloscStudentowNaRoku = _zbiorKartStudenckich.size();
}

void RocznikStudentow::ZapiszPlikStudentow(const string& nazwaPliku)
{
	fstream plik;
	plik.open(nazwaPliku, ios::out);
	if (plik.good())
	{
		for (auto itr = _zbiorKartStudenckich.begin(); itr != _zbiorKartStudenckich.end(); ++itr)
		{
			itr->WydrukStringStudent(plik);
		}
	}
	else { cout << "Plik niepoprawny." << endl; }
}

RocznikStudentow::RocznikStudentow()
{
	_iloscStudentowNaRoku = 0;
	_rocznik = 0;
}



