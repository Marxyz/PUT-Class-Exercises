#pragma once
#include "SegmentRobota.h"
#include <vector>

class Robot
{
public:


	std::vector<SegmentRobota> Zbior_Segementow;
	int x_glowne;
	int y_glowne;

	Robot();
	~Robot();
	void Rysuj();
	void RysujBaze();
	void ObrocSegment(int id, double kat);
};

