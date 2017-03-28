#pragma once
class SegmentRobota
{

	double _dlugoscBoku;
	double _szerokoscBoku;
	double _obecnyKat;
	double _r, _g, _b; // Kolor
	double _kat_pocz;

public:
	double ZwrocKatPocza();
	void ZapiszKatPoczatkowy();
	void Rysuj();
	double ZwrocObecnyKat();
	SegmentRobota();
	SegmentRobota(double KatPoczatkowy);
	void Obroc(double alfa);
};

