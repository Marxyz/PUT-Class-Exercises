#include "Header.h"
#include <iostream>

int main(int argc, char* argv[])
{
	KartaStudenta std1,std2,std3;
	std1.UstawWszystko("Arkadiusz", "Marks", 131335);
	std2.UstawWszystko("Agnieszka", "Gebala", 121345);
	std3.UstawWszystko("Mikolaj", "Majk", 124567);
	Ocena oc1;
	oc1.ocena = 4;
	oc1.NazwaPrzedmiotu = "Matematyka";
	Ocena oc2;
	oc2.ocena = 5;
	oc2.NazwaPrzedmiotu = "Informatyka";
	Ocena oc3, oc4;
	oc3.NazwaPrzedmiotu = "Fizyka";
	oc4.NazwaPrzedmiotu = "Informatyka";
	oc3.ocena = 4;
	oc4.ocena = 5;


	std1.DodajOcene(oc1);
	std1.DodajOcene(oc2);
	std2.DodajOcene(oc3);
	std2.DodajOcene(oc4);
	std3.DodajOcene(oc1);
	std3.DodajOcene(oc4);
	std3.DodajOcene(oc3);


	RocznikStudentow RSt;
	RSt.UstawRocznik(2017);
	RSt.DodajStudenta(std1);
	RSt.DodajStudenta(std2);
	RSt.DodajStudenta(std3);
	RSt.ZapiszPlikStudentow("dane.txt");

	RocznikStudentow RSt2;
	RSt2.UstawRocznik(2016);
	RSt2.SczytajPlikStudentow("dane.txt");
	BazaDanychStudentow bd_studentow;
	bd_studentow.DodajRocznikStudentow(RSt);
	bd_studentow.InformacjaORoczniku(2017, cout);

	
	bd_studentow.DodajRocznikStudentow(RSt2);
	//SORTUJ

	cout << "-----------SORT---------" << endl;
	bd_studentow.PosortujRocznikWgNazwisk(2017);
	bd_studentow.InformacjaORoczniku(2017,cout);

}
