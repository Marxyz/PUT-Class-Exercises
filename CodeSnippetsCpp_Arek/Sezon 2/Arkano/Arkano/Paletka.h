#pragma once
#include "Prostokat.h"
class Paletka :
	public Prostokat
{
public:
	void Zwieksz_Rozmiar(double ratio);
	Paletka(double dlugosc, double wysokosc, double speed);
	void Draw() override;
};

