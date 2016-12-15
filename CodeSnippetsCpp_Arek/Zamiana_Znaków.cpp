#include <iostream>
#include <map>
#include <string>

using namespace std;



int PobierzLiczbePodstawien()
{
	int liczba_podstawien = 0;
	bool flag = false;
	do
	{
		int l_podstawien;
		cout << "Podaj liczbe podstawien" << endl;
		cin >> l_podstawien;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(10, '\n');
			cin.sync();
		}
		else
		{
			liczba_podstawien = l_podstawien;
			flag = true;
		}
	} while (flag != true);
	return liczba_podstawien;
}
void PobierzPodstawienia(map<char, int>& slownik, int liczba_podstawien)
{
	int i = 0;
	while (i < liczba_podstawien)
	{
		int cyfra;
		char znak;
		cout << "Wpisz, ktory znak chcesz podstawic :" << endl;
		cin >> znak;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(10, '\n');
			cin.sync();
			continue;
		}
		cout << "Wpisz cyfre, ktora chcesz podstawic za znak :" << endl;
		cin >> cyfra;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(10, '\n');
			cin.sync();
			continue;
		}
		slownik[znak] = cyfra;
		i++;
	}
}

string PodmienZnaki(const map<char, int>& mapa, string wyraz) //powinno byc const map<char, int>& mapa ale wtedy przestaje dzia³aæ
{														//uzylem funkcji .at(), która kiedy w mapie nie ma odpowiedniego klucza wywala wyjatek, wiec umiescilem w try-catchu, no ale 
	string result;										//nie wiem czy tak mo¿na na zajeciach :P
	int len = wyraz.size();
	for (int i = 0; i < len; i++)
	{
		//if (mapa[wyraz[i]] != NULL)
		//{
		try
		{
			result += to_string(mapa.at(wyraz[i]));
		}
		//}
		//else{
		catch (out_of_range x)
		{
			result += wyraz[i];
		}
		//}	

	}
	return result;
}

int main()
{
	map<char, int> podstawienia;
	int liczba_podstawien;
	liczba_podstawien = PobierzLiczbePodstawien();
	PobierzPodstawienia(podstawienia, liczba_podstawien);
	string wyraz = "Moj stary jest fanatykiem wedkarstwa";
	string result = PodmienZnaki(podstawienia, wyraz);
	cout << result << endl;

	return 0;
}