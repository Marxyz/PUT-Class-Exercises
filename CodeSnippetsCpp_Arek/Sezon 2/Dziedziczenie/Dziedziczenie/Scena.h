#pragma once
#include <vector>
#include "Prostokat.h"

using namespace std;

//Aktywny po kliknieciu myszka
//Open gl - obsluga myszki

class Scena
{
public:

	Scena();
	void Idle();
	void Rysuj();
	void Klawisz(unsigned char znak, int x, int y);
	void Inicjuj();
	void Mysz(int button, int state, int x, int y);
	void Resize(int width, int height);
	void Aktualizuj();


	int actual;
	double _xmin,_ymin,_xmax,_ymax;

	void setActual(int i);

private:

	void DodajProstokat();
	void UsunProstokat();
	vector<Figura*> Zbior_Obiektow;
};
extern Scena scena;