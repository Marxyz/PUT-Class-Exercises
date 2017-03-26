#pragma once
#include <vector>
#include "SegmentRobota.h"

class Robot
{

	std::vector<SegmentRobota> Zbior_Segementow;
	double _x_glowne;
	double _y_glowne;

	int _iterZapisu = 0;
	int _iterAktualizacji = 0;
	double _xAktualizacji = 0;
	double _yAktualizacji = 0;

	int _aktywnySegment;
	double _r, _g, _b; // Kolor
	double _szerokoscBazy, _wysokoscBazy;
	std::vector<std::vector<double>> _wewnetrznaMacierzKatow;

public:
	
	void Aktualizuj(double czas);
	bool CzyZaktualizowane();
	void ZapamietajPunkt();

	int Rozmiar();

	void ZniszczSegment();

	void NastepnySegment();
	void PoprzedniSegment();

	void PrzesunWGore(double dy);
	void PrzesunWDol(double dy);
	void PrzesunWLewo(double dx);
	void PrzesunWPrawo(double dx);

	void DodajSegment(SegmentRobota& segment);
	void DodajSegment();

	void ObrocAktywnySegment(double kat);

	void RysujCalosc();
	Robot();
};

