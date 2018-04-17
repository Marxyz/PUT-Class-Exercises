#pragma once
#include <string>
#include <list>
#include <vector>

using namespace std;

/*
Napisz klasê KartaStudenta, z nastêpuj¹cymi sk³adowymi:
	imiê
	nazwisko
	nr indeksu
	lista ocen = lista dowolnej liczby struktur, zwieraj¹cych pola:
	nazwa przedmiotu
	ocena
	œredni¹ ocen, aktualizowan¹ automatycznie po dopisaniu oceny i nie mo¿liw¹ do zmiany przez u¿ytkownika klasy w inny sposób.
Nastêpnie napisz program, który umo¿liwi:
dodawanie list kart studentów wielu roczników (ka¿dy rok bêdzie mia³ inn¹ liczbê i nazwy przedmiotów),
do przechowywania listy roku powinien byæ wykorzystany odpowiedni kontener,
zapisywanie i odczyt kart ka¿dego rocznika z osobnych plików,
sortowanie list roczników wed³ug numeru indeksu i nazwiska (mo¿na za³o¿yæ ¿e nazwiska nie powtarzaj¹ siê),
ustalenie ilu studentów jest ³¹cznie wczytanych do programu, poprzez odwo³anie do odpowiedniej zmiennej, bez koniecznoœci obliczania jej.
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

