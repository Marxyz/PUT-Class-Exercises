#pragma once
#include "Prostokat.h"
#include "Scena.h"

class Klocek : public Prostokat
{


protected:


	int _punktacja;
	int _wytrzymalosc;

	int Zbicie(Scena& scena);

public:

	void Draw() override;
	virtual int Akcja(Scena& scena);
	Klocek();
	Klocek(double dlugosc, double wysokosc, int punktacja, int wytrzymalosc);
	Klocek(double dlugosc, double wysokosc);
};

