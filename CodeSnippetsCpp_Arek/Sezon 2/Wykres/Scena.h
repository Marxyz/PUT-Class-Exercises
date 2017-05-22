#pragma once
#include "Wykres.h"
#include <vector>
using namespace std;
class Scena
{
	//Aktywny po kliknieciu myszka
	//Open gl - obsluga myszki


private:
	float _mouse_x_down;
	float _mouse_y_down;
public:

	Scena();
	void Idle();
	void Rysuj();
	void Inicjuj();
	void Mysz(int button, int state, int x, int y);
	void Resize(int width, int height);
	void Aktualizuj();
	void PasywnaMysz(int x, int y);
	void Klawisz(unsigned char key, int x, int y);
	void ProjektujWidok() const;
	void MouseWheel(int button, int dir, int x, int y);


	void ZoomIn();
	void ZoomOut();

	void Fit();


	void Pan();

	float XMinSceny, XMaxSceny, YMinSceny, YMaxSceny;

	int actual;
	void setActual(int i);
	vector<Wykres> Zbior_Wykresow;
};
extern Scena scena;
