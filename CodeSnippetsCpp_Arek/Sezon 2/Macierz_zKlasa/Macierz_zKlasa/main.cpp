
#include "Macierz.h"


int main(int argc, char* argv[])
{
	Macierz test(2, 3),test2,test3;
	test.Wyswietl();
	test2.PobierzMacierz();
	test.PobierzMacierz();
	test3 = test2.DodajMacierz(test);
	test2.Wyswietl();
	string testS;
	testS = test3.ToString();

	return 0;
}
