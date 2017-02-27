#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Cialo_Niebieskie
{
	char Nazwa[32];
	double Masa;
};

bool Sortuj_Wg_Masy(const Cialo_Niebieskie& pl1, const Cialo_Niebieskie& pl2)
{
	return pl1.Masa > pl2.Masa;
}

int main()
{
	vector<Cialo_Niebieskie> Lista_Planet;

	//Odczyt

	fstream plik;
	plik.open("uklad_sloneczny.bin", ios::binary | ios::in);
	if (plik.good())
	{
		cout << "Plik poprawnie otworzony" << endl;
		plik.seekg(0, ios_base::end);
		int rozmiar = plik.tellp();
		plik.seekg(0, ios_base::beg);

		int ilosc_struktur = rozmiar / sizeof(Cialo_Niebieskie);

		for (int i = 0; i < ilosc_struktur; i++)
		{
			Cialo_Niebieskie tmp;
			char nazwa[32];
			double Masa;
			plik.read(nazwa, sizeof(char) * 32);
			plik.read((char*)&Masa, sizeof(double));
			tmp.Masa = Masa;
			strcpy(tmp.Nazwa, nazwa);
			Lista_Planet.push_back(tmp);
			
		}

	}

	//Operacje 

	sort(Lista_Planet.begin(), Lista_Planet.end(), Sortuj_Wg_Masy);

	// Zapis

	fstream plik_do_zapisu;
	plik_do_zapisu.open("uklad_sloneczny_zapis.bin", ios::binary | ios::out);
	for (int j = 0; j < 3; j++)
	{
		plik_do_zapisu.write((char*)&Lista_Planet[j], sizeof(Cialo_Niebieskie));
	}

	return 0;
}