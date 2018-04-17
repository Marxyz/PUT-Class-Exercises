#include "Header.h"

void KartaStudenta::UstawNazwisko(const string& nazwisko)
{
	_nazwisko = nazwisko;
}

void KartaStudenta::UstawImie(const string& imie)
{
	_imie = imie;
}

void KartaStudenta::UstawIndex(unsigned long index_nr)
{
	_indexNr = index_nr;
}

void KartaStudenta::UstawWszystko(const string& imie, const string& nazwisko, unsigned long index_nr)
{
	_imie = imie;
	_nazwisko = nazwisko;
	_indexNr = index_nr;
}

string KartaStudenta::ZwrocNazwisko()
{
	return _nazwisko;
}

double KartaStudenta::PokazSredniaStudenta()
{
	return _sredniaOcen;
}

unsigned long KartaStudenta::ZwrocIndex()
{
	return _indexNr;
}

void KartaStudenta::DodajOcene(Ocena ocena)
{
	_listaOcen.push_front(ocena);
	double suma = 0;
	for (auto itr = _listaOcen.begin(); itr != _listaOcen.end(); ++itr)
	{
		suma += itr->ocena;
	}
	_sredniaOcen = 1.0 * suma / _listaOcen.size();
}

string KartaStudenta::StudentToString()
{
	string result;
	result = _imie + ';' + _nazwisko + ';' + to_string(_indexNr) + ';' + to_string(_sredniaOcen) + ';';
	for (auto itr = _listaOcen.begin(); itr != _listaOcen.end(); ++itr)
	{
		result += itr->NazwaPrzedmiotu + ":" + to_string(itr->ocena) + ",";
	}
	return result;
}

void KartaStudenta::WydrukStudenta(ostream& stream)
{
	string result = "Student: " + _imie + " " + _nazwisko + "\nIndex: " + to_string(_indexNr) + "\nSrednia: " + to_string(_sredniaOcen) + "\nOceny:\n";
	for (auto itr = _listaOcen.begin(); itr != _listaOcen.end(); ++itr)
	{
		result += itr->NazwaPrzedmiotu + ": " + to_string(itr->ocena) + ", ";
	}
	result += "\n\n";
	stream << result;
}

void KartaStudenta::SczytajStudentaString(string input)
{
	bool flag = true;
	int pos = input.find(';');
	_imie = input.substr(0, pos);
	input = input.substr(pos + 1);
	pos = input.find(';');
	_nazwisko = input.substr(0, pos);
	input = input.substr(pos + 1);
	pos = input.find(';');
	_indexNr = stoi(input.substr(0, pos));
	input = input.substr(pos + 1);
	pos = input.find(';');
	_sredniaOcen = stod(input.substr(0, pos));
	input = input.substr(pos + 1);
	while (flag)
	{
		pos = input.find(',');
		if (pos == -1)
		{
			break;
		}
		int helper;
		Ocena tmp;
		helper = input.find(':');
		if (helper == -1)
		{
			break;
		}
		tmp.NazwaPrzedmiotu = input.substr(0, helper);
		input = input.substr(helper + 1);
		tmp.ocena = stoi(input.substr(0, pos));
		input = input.substr(2);
		this->DodajOcene(tmp);
	}

}

void KartaStudenta::WydrukStringStudent(ostream& stream)
{
	stream << this->StudentToString() << endl;
}

KartaStudenta::KartaStudenta() : _indexNr(0), _sredniaOcen(0)
{
}

