#pragma once
#include "Wykres.h"
#include <vector>
using namespace std;
class Scena
{
	//Aktywny po kliknieciu myszka
	//Open gl - obsluga myszki
	public:

		Scena();
		void Idle();
		void Rysuj();
		void Inicjuj();
		void Mysz(int button, int state, int x, int y);
		void Resize(int width, int height);
		void Aktualizuj();
		void PasywnaMysz(int x, int y);

		void setActual(int i);
		vector<Wykres> Zbior_Wykresow;
	private:


	};
	extern Scena scena;
};

