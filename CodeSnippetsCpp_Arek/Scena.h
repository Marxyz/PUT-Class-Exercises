#pragma once
#include <vector>
#include "Prostokat.h"

using namespace std;
//Aktywny po kliknieciu myszka
//Open gl - obsluga myszki
//pixele to pixe le okna
//GLFRUSTRUt
class Scena
{
public:
	Scena();
	void Idle();
	void Rysuj();
	void Klawisz(unsigned char znak, int x, int y);
	void Inicjuj();
	void Resize(int width, int height);
	int actual;
private:
	void DodajProstokat();
	void UsunProstokat();
	vector<Figura*> Zbior_Figur;
};
extern Scena scena;