
#include "Macierz.h"
#include <iostream>



int main(int argc, char* argv[])
{
	Macierz test("-3,2,1,4,;2,3,0,1,;1,2,3,2,;1,1,1,1,;");
	cout << "Macierz testowa: " << endl << test << endl;
	cout << "Macierz odwrotna: " << endl << test.StworzMacierzOdwrotna() << endl << "Macierz transponowana: " << endl << test.StworzMacierzTransponowana() <<
		endl << "Wyznacznik: " << test.ObliczWyznacznik() << endl << endl << "Wynik dzialania: " << endl << test*test.ObliczWyznacznik() + test + 2 * test - test * 5 << endl;
	Macierz test2;
	cin >> test2;
}

