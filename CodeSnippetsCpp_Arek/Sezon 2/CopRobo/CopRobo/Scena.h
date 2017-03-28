#pragma once
#include <vector>
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
	bool CzyZaktualizowane = true;
private:
	int actual;
	vector<Robot> Zbior_robotow;
};
extern Scena scena;

