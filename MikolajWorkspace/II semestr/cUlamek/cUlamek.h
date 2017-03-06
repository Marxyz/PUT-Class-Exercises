#ifndef CULAMEK_h
#define CULAMEK_H
#include <iostream>

class cUlamek{
private:
	int _licznik;
	int _mianownik;
private:
	void Skroc();
public:
	cUlamek();
	cUlamek(int a, int b);

	cUlamek operator+(int a) const;
	cUlamek operator+(const cUlamek& u) const;
	cUlamek operator=(int a);
	cUlamek operator=(const cUlamek&u);
	cUlamek operator*(int a) const;
	void setLicznik(int a);
	int getLicznik();
	operator double();
	/*
	friend istream operator>>(istream &str, cUlamek&u);
	friend &ostream operator<<(ostream &str, cUlamek&u);
	*/

};


#endif
