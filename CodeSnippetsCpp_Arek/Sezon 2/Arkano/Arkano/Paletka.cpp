#include "Paletka.h"


void Paletka::Zwieksz_Rozmiar(double ratio)
{
	this->_dlugosc *= ratio;
}

Paletka::Paletka(double dlugosc, double wysokosc, double speed):Prostokat(dlugosc,wysokosc,speed)
{
}


void Paletka::Draw()
{
	Prostokat(*this).Draw();
}
