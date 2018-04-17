#pragma once
#include <string>
#include <list>
#include <vector>

using namespace std;

/*
Napisz klas� KartaStudenta, z nast�puj�cymi sk�adowymi:
	imi�
	nazwisko
	nr indeksu
	lista ocen = lista dowolnej liczby struktur, zwieraj�cych pola:
	nazwa przedmiotu
	ocena
	�redni� ocen, aktualizowan� automatycznie po dopisaniu oceny i nie mo�liw� do zmiany przez u�ytkownika klasy w inny spos�b.
Nast�pnie napisz program, kt�ry umo�liwi:
dodawanie list kart student�w wielu rocznik�w (ka�dy rok b�dzie mia� inn� liczb� i nazwy przedmiot�w),
do przechowywania listy roku powinien by� wykorzystany odpowiedni kontener,
zapisywanie i odczyt kart ka�dego rocznika z osobnych plik�w,
sortowanie list rocznik�w wed�ug numeru indeksu i nazwiska (mo�na za�o�y� �e nazwiska nie powtarzaj� si�),
ustalenie ilu student�w jest ��cznie wczytanych do programu, poprzez odwo�anie do odpowiedniej zmiennej, bez konieczno�ci obliczania jej.
*/

struct Ocena
{
	string NazwaPrzedmiotu;
	int ocena;
};

class KartaStudenta
{

private:

	string _imie;
	string _nazwisko;
	unsigned long int _indexNr;
	list<Ocena> _listaOcen;
	double _sredniaOcen;

public:

	//Setters

	void UstawNazwisko(const string& nazwisko);
	void UstawImie(const string& imie);
	void UstawIndex(unsigned long int index_nr);
	void UstawWszystko(const string& imie, const string& nazwisko, unsigned long int index_nr);

	//Getters

	string ZwrocNazwisko();
	double PokazSredniaStudenta();
	unsigned long int ZwrocIndex();

	//Methods

	void DodajOcene(Ocena ocena);
	string StudentToString();
	void WydrukStudenta(ostream& stream);
	void SczytajStudentaString(string input);
	void WydrukStringStudent(ostream& stream);
	//Konstruktory i Destruktory

	KartaStudenta();


};

class RocznikStudentow
{

private:

	int _rocznik;
	vector<KartaStudenta> _zbiorKartStudenckich;
	int _iloscStudentowNaRoku;

public:

	//Setters
	void UstawRocznik(int rocznik);

	//Getters
	int ZwrocIloscStudentowNaRoku();
	int ZwrocRocznik();

	//Methods

	KartaStudenta& ZnajdzStudenta(int index);
	void PosortujStudentowWgNazwisk();
	void PosortujStudentowWgIndexow();
	void InformacjaORoczniku(ostream& stream);
	void WydrukStudentow(ostream& stream);
	void SczytajPlikStudentow(const string& nazwaPliku);
	void DodajStudenta(KartaStudenta &student);
	void ZapiszPlikStudentow(const string& nazwaPliku);
	//Konstruktory i destruktory


	RocznikStudentow();
	
};

class BazaDanychStudentow
{

private:

	vector<RocznikStudentow> _zbiorRocznikow;
	int _ogolnaIloscStudentow;



	//Methods

	RocznikStudentow& ZnajdzRocznik(int rocznik);

public:
	//Setters
	
	//Getters
	int ZwrocOgolnaLiczbeStudentow();

	//Methods
	void DodajRocznikStudentow(RocznikStudentow& rocznik);
	void InformacjaORoczniku(int rocznik, ostream& strumien);
	void PosortujRocznikWgIndexow(int rocznik);
	void PosortujRocznikWgNazwisk(int rocznik);
	//Konstruktory i destruktory

	BazaDanychStudentow();
};

