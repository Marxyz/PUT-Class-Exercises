#pragma once
class SegmentRobota
{

	double _dlugoscBoku;
	double _szerokoscBoku;
	double _katPoczatkowy;
	double _r, _g, _b; // Kolor
public:
	void Rysuj();
	double ZwrocKatPoczakowy();
	SegmentRobota();
	SegmentRobota(double KatPoczatkowy);
	void Obroc(double alfa);
};

