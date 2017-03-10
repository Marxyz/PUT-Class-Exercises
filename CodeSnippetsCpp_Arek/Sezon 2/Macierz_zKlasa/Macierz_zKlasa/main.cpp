
#include "Macierz.h"



int main(int argc, char* argv[])
{
	Macierz test("-1,-2,;-3,-1,;-1,2,;");
	Macierz test2("0,3,2,;-2,-1,-4,;");
	auto r = test2 * test;
	r.Wyswietl();
	auto res = 2 * test2 * 2 * test;
	res.Wyswietl();
}
