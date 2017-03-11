#include "Macierz.h"

Macierz::Macierz()
{
	wektor.resize(0);
}

Macierz::Macierz(Macierz & M)
{
	this->wektor = M.wektor;
}

void Macierz::SetMacierz()
{
	int a,b;
	cout << "Podaj wymiary macierzy." << endl;
	cin >> b >> a;
	wektor.resize(a);
	for (int i = 0; i < a; i++) {
		wektor[i].resize(b);
	}
	cout << "Wypelnij macierz." << endl;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cin>>wektor[i][j];
		}
	}
}

void Macierz::DispMacierz()
{
	for (int i = 0; i < wektor.size(); i++) {
		for (int j = 0; j < wektor[i].size(); j++) {
			cout<<wektor[i][j] <<'\t';
		}
		cout << endl;
	}
}

Macierz Macierz::operator+(const Macierz & M)
{
	
	return Macierz();
}
