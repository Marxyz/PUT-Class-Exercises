#pragma once
#include <vector>
#include "Prostokat.h"
#include "Robot.h"

using namespace std;

class Scena
{
public:
	Scena();
	void Idle();
	void Rysuj();
	void Klawisz(unsigned char znak, int x, int y);
	void Inicjuj();
	void Resize(int width,int height);
private:
	void DodajProstokat();
	void UsunProstokat();
	int actual;
	double _czasIdle;
	bool _aktualizuj = false;
	vector<Prostokat> Zbior_prostokatow;
	vector<Robot> Zbior_robotow;
};
extern Scena scena;

