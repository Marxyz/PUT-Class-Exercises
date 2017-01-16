#include <string>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct Dziecko
{
	string Name;
	string Surname;
	int x;
	int y;
};

void WypelnTabliceDzieci(vector<Dziecko>& ListaDzieci, int ile)
{
	string alphabet = "abcdefghijklmnoprstuwxyz";
	ListaDzieci.resize(ile);
	for (int i = 0; i < ile; i++)
	{
		string surname;
		string name;
		for (int j = 0; j < 10; j++)
		{
			name += alphabet[rand() % alphabet.size()];
		}
		for (int surname_letter_it = 0; surname_letter_it < 10; surname_letter_it++)
		{
			surname += alphabet[rand() % alphabet.size()];
		}
		ListaDzieci[i].Surname = surname;
		ListaDzieci[i].Name = name;
		ListaDzieci[i].x = rand() % 10;
		ListaDzieci[i].y = rand() % 10;
	}
}

bool KtoBlizszy(Dziecko& dziecko1, Dziecko& dziecko2)
{
	if (dziecko1.x * dziecko1.x + dziecko1.y * dziecko1.y < dziecko2.x * dziecko2.x + dziecko2.y * dziecko2.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool SortujWgNazwiska(Dziecko& dziecko1, Dziecko& dziecko2)
{
	if (dziecko1.Surname < dziecko2.Surname)
	{
		return true;
	}
	else
	{
		if (dziecko1.Surname == dziecko2.Surname)
		{
			if (dziecko1.Name < dziecko2.Name)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
}

void wyswietlTabliczeDzieci(vector<Dziecko>& ListaDzieci)
{
	for (int i = 0; i < ListaDzieci.size(); i++)
	{
		cout << ListaDzieci[i].Name << "  " << ListaDzieci[i].Surname << "  " << ListaDzieci[i].x << "  " << ListaDzieci[i].y << endl;
	}
}

bool czyBlisko(Dziecko& dziecko)
{
	return sqrt(pow(dziecko.x, 2) + pow(dziecko.y, 2)) < 10;
}

void main()
{
	srand(time(0));
	vector<Dziecko> Zbior_Dzieci;
	/*WypelnTabliceDzieci(Zbior_Dzieci,5);*/
	Zbior_Dzieci.push_back({ "Miki","LSD",1,2 });
	Zbior_Dzieci.push_back({ "Agnieszka","Gebala",1,1 });
	Zbior_Dzieci.push_back({ "Arek","Marks",2,2 });
	Zbior_Dzieci.push_back({ "Barabaeusz","Marks",3,5 });
	Zbior_Dzieci.push_back({ "Ignacy","Nomenomen" ,5,5 });
	wyswietlTabliczeDzieci(Zbior_Dzieci);
	cout << " - - - - - - - - - S - O - R - T - - - - - - - - - -  " << endl;
	/*sort(Zbior_Dzieci.begin(), Zbior_Dzieci.end(), KtoBlizszy);*/
	sort(Zbior_Dzieci.begin(), Zbior_Dzieci.end(), SortujWgNazwiska);
	vector<Dziecko>::iterator it = find_if(Zbior_Dzieci.begin(), Zbior_Dzieci.end(), czyBlisko);
	cout << "Dziecko blizej niz 10 jednostek to " << it->Name << endl;
	wyswietlTabliczeDzieci(Zbior_Dzieci);
}