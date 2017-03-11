#include "Macierz.h"
#include <iostream>
#include <string>
#include <algorithm>;
using namespace std;

string ReplaceString(string subject, const string& search,
	const string& replace) {
	int pos = 0;
	while ((pos = subject.find(search, pos)) != string::npos)
	{

		subject.replace(pos, search.length(), replace);
	}
	return subject;
}

int FindNumberOfOccurence(const string& subject, const char search)
{
	return count(subject.begin(), subject.end(), search);
}




Macierz Macierz::PomnozMacierz(const int skalar)
{
	Macierz tmp;
	tmp.UstawRozmiarWypelnZerem(_iloscRzedow, _iloscKolumn);
	tmp = *this;
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


Macierz Macierz::DodajMacierz(const Macierz& macierzB)
{
	Macierz tmp;
	tmp = *this;
	if (macierzB._iloscKolumn != _iloscKolumn || macierzB._iloscRzedow != _iloscRzedow)
	{
		cout << "Operacja niemo¿liwa do zrealizowania, rozmiary nie sa identyczne." << endl;
		return Macierz(_iloscRzedow, _iloscKolumn);
	}
	for (int c = 0; c < tmp._iloscRzedow; c++)
	{
		for (int r = 0; r < tmp._iloscKolumn; r++)
		{
			tmp._zasob[c][r] += macierzB._zasob[c][r];
		}
	}

	return tmp;
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

void Macierz::MacierzFromString(string input)
{
	string temp = input;
	int co_ile = 0;
	int helper = 0;
	_iloscRzedow = FindNumberOfOccurence(temp, ';');
	temp = temp.substr(0, input.find(';') + 1);
	_iloscKolumn = FindNumberOfOccurence(temp, ',');
	UstawRozmiarWypelnZerem(_iloscRzedow, _iloscKolumn);
	input = ReplaceString(input, ";", "");
	input = ReplaceString(input, ",", "");
	for (int i = 0; i < _iloscRzedow; i++)
	{

		for (int i2 = 0; i2 < _iloscKolumn; i2++)
		{
			if (input[co_ile + i2 + helper] == '-')
			{
				_zasob[i][i2] = (input[co_ile + helper + i2 + 1] - '0')*(-1);
				helper++;
			}
			else
			{
				_zasob[i][i2] = (input[co_ile + i2 + helper] - '0');
			}

		}
		co_ile += _iloscKolumn;
	}


}

Macierz Macierz::Poteguj(const int n)
{
	if (n < 0)
	{
		cout << "Wykladnik powinien byc wiekszy od 0." << endl;
		return Macierz(_iloscRzedow, _iloscKolumn);
	}
	if (n == 1)
	{
		return *this;
	}
	return Poteguj(n - 1) * *this;
}

Macierz Macierz::StworzDopelnienie(int wiersz, int kolumna)
{
	Macierz tmp(_iloscRzedow - 1, _iloscKolumn - 1);
	int tmp_k = 0;
	int tmp_w = 0;
	for (int w = 0; w < _iloscRzedow; w++)
	{
		tmp_k = 0;
		for (int k = 0; k < _iloscKolumn; k++)
		{
			if (w == wiersz || k == kolumna)
			{
				continue;
			}
			tmp._zasob[tmp_w][tmp_k] = _zasob[w][k];
			tmp_k++;
		}
		if (w != wiersz)
		{
			tmp_w++;
		}
	}
	return tmp;
}

int Macierz::ObliczWyznacznik()
{
	int stopien = _iloscKolumn;
	double wyzn = 0;
	if (stopien == 1)
	{
		return _zasob[0][0];
	}
	for (int w = 0; w < _iloscRzedow ; w++)
	{
		wyzn += this->StworzDopelnienie(w, 0).ObliczWyznacznik() * (_zasob[w][0] * pow(-1, w + 0));
	}
	return wyzn;
}

Macierz Macierz::operator^(const int n)
{
	return this->Poteguj(n);
}

Macierz Macierz::operator+(const Macierz& macierzB)
{
	return this->DodajMacierz(macierzB);
}

Macierz Macierz::operator-(const Macierz& macierzB)
{
	return this->OdejmijMacierz(macierzB);
}

Macierz Macierz::operator*(const Macierz& macierzB)
{
	return this->PomnozMacierz(macierzB);
}

Macierz Macierz::operator*(const int skalar)
{
	return this->PomnozMacierz(skalar);
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
		result += ';';
	}
	return result;
}

Macierz Macierz::PomnozMacierz(const Macierz& macierzB)
{
	Macierz result;
	if (_iloscKolumn != macierzB._iloscRzedow)
	{
		cout << "Wymmiary macierzy sa nieprawidlowe." << endl;
		result.UstawRozmiarWypelnZerem(_iloscRzedow, _iloscKolumn);
		return result;
	}
	result.UstawRozmiarWypelnZerem(_iloscRzedow, macierzB._iloscKolumn);
	for (int i = 0; i < result._iloscRzedow; i++)
	{
		for (int j = 0; j < result._iloscKolumn; j++)
		{
			for (int k = 0; k < _iloscKolumn; k++)
			{
				result._zasob[i][j] += _zasob[i][k] * macierzB._zasob[k][j];
			}
		}
	}
	return result;


}

Macierz Macierz::OdejmijMacierz(const Macierz& macierzB)
{
	Macierz tmp;
	tmp = *this;
	if (macierzB._iloscKolumn != _iloscKolumn || macierzB._iloscRzedow != _iloscRzedow)
	{
		cout << "Operacja niemo¿liwa do zrealizowania, rozmiary nie sa identyczne." << endl;
		return Macierz(_iloscRzedow, _iloscKolumn);
	}
	for (int c = 0; c < tmp._iloscRzedow; c++)
	{
		for (int r = 0; r < tmp._iloscKolumn; r++)
		{
			tmp._zasob[c][r] -= macierzB._zasob[c][r];
		}
	}

	return tmp;
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

	UstawRozmiarWypelnZerem(_iloscRzedow, _iloscKolumn);

	for (int c = 0; c < _iloscRzedow; c++)
	{
		for (int r = 0; r < _iloscKolumn; r++)
		{
			do
			{
				cout << "Podaj wartosc " + to_string(c) + " kolumny i " + to_string(r) + " rzedu: " << endl;
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

Macierz::Macierz(const string input)
{
	this->MacierzFromString(input);
}

Macierz operator*(const int& lhs, Macierz& rhs)
{
	return rhs * lhs;
}

