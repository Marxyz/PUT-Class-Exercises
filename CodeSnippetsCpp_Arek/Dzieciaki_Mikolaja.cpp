#include <string>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

struct Dziecko
{
	string Name;
	int x;
	int y;
};

void WypelnTabliceDzieci(vector<Dziecko>& ListaDzieci, int ile)
{
	string alphabet = "abcdefghijklmnoprstuwxyz";
	ListaDzieci.resize(ile);
	for (int i = 0; i < ile; i++)
	{
		string name;
		for (int j = 0; j < 10; j++)
		{
			name += alphabet[rand() % alphabet.size()];
		}
		ListaDzieci[i].Name = name;
		ListaDzieci[i].x = rand() % 100;
		ListaDzieci[i].y = rand() % 100;
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


void wyswietlTabliczeDzieci(vector<Dziecko>& ListaDzieci)
{
	for (int i = 0; i < ListaDzieci.size(); i++)
	{
		cout << ListaDzieci[i].Name << "  " << ListaDzieci[i].x << "  " << ListaDzieci[i].y << endl;
	}
}

void main()
{
	srand(time(0));
	vector<Dziecko> Zbior_Dzieci;
	WypelnTabliceDzieci(Zbior_Dzieci,5);
	wyswietlTabliczeDzieci(Zbior_Dzieci);
	cout << " - - - - - - - - - S - O - R - T - - - - - - - - - -  " << endl;
	sort(Zbior_Dzieci.begin(), Zbior_Dzieci.end(), KtoBlizszy);
	wyswietlTabliczeDzieci(Zbior_Dzieci);
}