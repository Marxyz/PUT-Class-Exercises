
#include "Macierz.h"
#include <iostream>


int main(int argc, char* argv[])
{
	Macierz test("-3,2,1,4,;2,3,0,1,;1,2,3,2,;1,1,1,1,;");
	test.StworzDopelnienie(1,2).Wyswietl();
	cout << "Wyznacznik: " << test.ObliczWyznacznik() << endl;
}
