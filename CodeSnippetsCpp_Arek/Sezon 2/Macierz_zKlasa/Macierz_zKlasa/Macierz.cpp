#include "Macierz.h"
#include <iostream>
#include <string>
using namespace std;

Macierz Macierz::PomnozMacierz(int skalar)
{
	Macierz tmp;
	tmp.UstawRozmiarWypelnZerem(_iloscRzedow, _iloscKolumn);
	for (auto itr = tmp._zasob.begin(); itr != tmp._zasob.end(); ++itr)
	{
		for (auto itr2 = itr->begin(); itr2 != itr->end(); ++itr2)
		{
			int wartosc = *itr2;
			*itr2 = wartosc * skalar;
		}
	}
	return tmp;
	
}

Macierz Macierz::DodajMacierz(Macierz& macierzB)
{
	if (macierzB._iloscKolumn != _iloscKolumn || macierzB._iloscRzedow != _iloscRzedow )
	{
		cout << "Operacja niemo¿liwa do zrealizowania, rozmiary nie sa identyczne." << endl;
		return *this;
	}
	for (int c = 0; c < _iloscRzedow; c++)
	{
		for (int r = 0; r < _iloscKolumn; r++)
		{
			_zasob[c][r] += macierzB._zasob[c][r];
		}
	}

	return *this;
}

void Macierz::UstawRozmiarWypelnZerem(int wysokosc, int szerokosc)
{
	_iloscKolumn = szerokosc;
	_iloscRzedow = wysokosc;
	_zasob.resize(wysokosc);
	for (auto itr = _zasob.begin(); itr != _zasob.end(); ++itr)
	{
		itr->resize(szerokosc);
		for (auto itr2 = itr->begin(); itr2 != itr->end(); ++itr2)
		{
			*itr2 = 0;
		}
	}
}

string Macierz::ToString()
{
	string result;
	for (auto itr = _zasob.begin(); itr != _zasob.end(); ++itr)
	{
		for (auto itr2 = itr->begin(); itr2 != itr->end(); ++itr2)
		{
			result += to_string(*itr2) + ',';
		}
		result += '\n';
	}
	return result;
}

Macierz Macierz::OdejmijMacierz(Macierz& macierzB)
{
	if (macierzB._iloscKolumn != _iloscKolumn || macierzB._iloscRzedow != _iloscRzedow)
	{
		cout << "Operacja niemo¿liwa do zrealizowania, rozmiary nie sa identyczne." << endl;
		return *this;
	}
	for (int c = 0; c < _iloscRzedow; c++)
	{
		for (int r = 0; r < _iloscKolumn; r++)
		{
			_zasob[c][r] -= macierzB._zasob[c][r];
		}
	}

	return *this;
}


void Macierz::PobierzMacierz()
{
	do
	{
		cout << "Podaj wysokosc macierzy: " << endl;
		cin >> _iloscRzedow;
		if (cin.fail())
		{
			cin.clear(cin.goodbit);
			cin.ignore(20, '\n');
			continue;
		}
		break;

	} while (true);
	do
	{
		cout << "Podaj szerokosc macierzy: " << endl;
		cin >> _iloscKolumn;

		if (cin.fail())
		{
			cin.clear(cin.goodbit);
			cin.ignore(20, '\n');
			continue;
		}
		break;
	} while (true);

	UstawRozmiarWypelnZerem(_iloscKolumn, _iloscRzedow);
	
	for (int c = 0; c  < _iloscRzedow ; c++)
	{
		for (int r = 0; r < _iloscKolumn; r++)
		{
			do
			{
				cout << "Podaj wartosc " + to_string(c) + " kolumny i " + to_string(r)  + " rzedu: " << endl;
				cin >> _zasob[c][r];

				if (cin.fail())
				{
					cin.clear(cin.goodbit);
					cin.ignore(20, '\n');
					continue;
				}
				break;
			} while (true);
		}
	}


}

void Macierz::Wyswietl()
{
	for (auto itr = _zasob.begin(); itr != _zasob.end(); ++itr)
	{
		for (auto itr2 = itr->begin(); itr2 != itr->end(); ++itr2)
		{
			cout << *itr2 << " ";
		}
		cout << endl;
	}
}

Macierz::Macierz() : _iloscKolumn(1), _iloscRzedow(1)
{
	UstawRozmiarWypelnZerem(_iloscKolumn, _iloscRzedow);
}

Macierz::Macierz(int wysokosc, int szerokosc)
{
	UstawRozmiarWypelnZerem(wysokosc, szerokosc);
}

