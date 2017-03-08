#include "Macierz.h"
#include <string>

using namespace std;

void Macierz::UstawRozmiar(int wysokosc, int szerokosc)
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

	UstawRozmiar(_iloscKolumn, _iloscRzedow);
	
	for (int c = 0; c  < _iloscRzedow ; c++)
	{
		for (int r = 0; r < _iloscKolumn; r++)
		{
			do
			{
				cout << "Podaj wartosc " + to_string(c) + " kolumny i " + std::to_string(r)  + " rzedu: " << endl;
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
	UstawRozmiar(_iloscKolumn, _iloscRzedow);
}

Macierz::Macierz(int wysokosc, int szerokosc)
{
	UstawRozmiar(wysokosc, szerokosc);
}

