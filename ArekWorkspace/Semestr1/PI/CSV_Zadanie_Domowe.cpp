#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Samochod
{
	int Rok_Produkcji;
	string Kraj_Pochodzenia;
	string Nazwa;
	int Maksymalna_Predkosc;
};

Samochod Sczytaj_Linie(string linia)
{
	Samochod tmp;
	int pos = linia.find(';');
	tmp.Rok_Produkcji = stoi(linia.substr(0, pos));
	linia = linia.substr(pos + 1);
	pos = linia.find(';');
	tmp.Kraj_Pochodzenia = linia.substr(0, pos);
	linia = linia.substr(pos + 1);
	pos = linia.find(';');
	tmp.Nazwa = linia.substr(0, pos);
	linia = linia.substr(pos + 1);
	pos = linia.find(' ');
	tmp.Maksymalna_Predkosc = stoi(linia.substr(0, pos));

	return tmp;
}

vector<Samochod> Samochody_Po_300(const vector<Samochod>& Samochody)
{
	vector<Samochod> Samochody_Po_300;
	for (auto itr = Samochody.begin(); itr != Samochody.end(); itr++)
	{
		if (itr->Maksymalna_Predkosc > 300)
		{
			Samochody_Po_300.push_back(*itr);
		}
	}
	return Samochody_Po_300;
}

Samochod Ktory_pierwszy_powyzej_300(const vector<Samochod>& Samochody)
{
	int	rok_prod = Samochody[0].Rok_Produkcji;
	Samochod tmp;
	for (auto itr = Samochody.begin(); itr != Samochody.end(); itr++)
	{
		if (itr->Rok_Produkcji < rok_prod)
		{
			rok_prod = itr->Rok_Produkcji;
			tmp = *itr;
		}
	}
	return tmp;
}

void Wyswietl_Autko(Samochod samo)
{
	cout << samo.Rok_Produkcji << "  " << samo.Kraj_Pochodzenia << "  " << samo.Nazwa << "  " << samo.Maksymalna_Predkosc << endl;
}

bool Sortuj_Wg_Nazwy(const Samochod&s1, const Samochod&s2 )
{
	return s1.Nazwa < s2.Nazwa;
}

int main()
{
	// Odczyt

	vector<Samochod> Samochody;
	fstream plik;
	plik.open("cars.csv", ios::in);
	if (plik.good())
	{
		cout << "Plik otworzony" << endl;
		while (!plik.eof())
		{
			string linia;
			getline(plik, linia);
			Samochod tmp = Sczytaj_Linie(linia);
			Samochody.push_back(tmp);
		}
		plik.close();
	}
	else
	{
		cout << "Cos poszlo nie tak " << endl;
		return 1;
	}

	//Operacje
	
	vector<Samochod> Samochody_Przekr_300 = Samochody_Po_300(Samochody);

	cout << "Ilosc samochodow przkraczajacych predkosc 300 km/h: " << Samochody_Przekr_300.size() << endl;

	Samochod pierwszy_pow_300 = Ktory_pierwszy_powyzej_300(Samochody_Przekr_300);

	Wyswietl_Autko(pierwszy_pow_300);

	sort(Samochody.begin(), Samochody.end(), Sortuj_Wg_Nazwy);

	// Zapis

	fstream plik_do_zapisu;
	plik_do_zapisu.open("cars_save.csv", ios::out);
	for (int i = 0; i <Samochody.size();  i++)
	{
		plik_do_zapisu << Samochody[i].Rok_Produkcji << ";" << Samochody[i].Kraj_Pochodzenia << ";" << Samochody[i].Nazwa << ";" << Samochody[i].Maksymalna_Predkosc << " km/h" << endl;
 	}
	plik_do_zapisu.close();
	return 0;
}