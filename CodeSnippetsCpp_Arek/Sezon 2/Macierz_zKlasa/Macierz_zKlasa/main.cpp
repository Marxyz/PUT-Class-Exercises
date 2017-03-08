
#include "Macierz.h"


int main(int argc, char* argv[])
{
	Macierz test(2, 3),test3;
	test.Wyswietl();
	Macierz test2;
	test2.PobierzMacierz();
	test2.Wyswietl();
	test3.Wyswietl();
	return 0;
}
