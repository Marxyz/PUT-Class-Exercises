#pragma once
#include "Klocek.h"
class Klocek_Paletkowy :
	public Klocek
{
public:
	
	int Akcja(Scena & scena) override;
	Klocek_Paletkowy(double dlugosc, double wysokosc, int punktacja, int wytrzymalosc);
	void Draw() override;
};

