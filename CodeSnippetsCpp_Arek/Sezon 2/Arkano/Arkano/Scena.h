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
	void Inicjuj();
	void Mysz(int button, int state, int x, int y);
	void Resize(int width, int height);
	void Aktualizuj();
	void PasywnaMysz(int x, int y);

	static void PrzerwijGre();

	double predkosc;
	int actual;
	int punktacja;
	double _xmin, _ymin, _xmax, _ymax;

	void setActual(int i);
	vector<Figura*> Zbior_Obiektow;
private:

	
};
extern Scena scena;