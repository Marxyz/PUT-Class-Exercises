#pragma once
#include <vector>
#include "cFigura.h"
#include "cProstokat.h"
#include <GL/freeglut.h>
#include "cOkrag.h"
#include "cTrojkat.h"
#include <iostream>


class cScene
{
	std::vector<cFigura*> obiekty;
	int active;
	int punkty;
	bool loose;
public:
	double xmin, xmax, ymin, ymax;
	cScene();
	~cScene();
	void Idle();
	void Init();
	void Draw();
	void Keyboard(unsigned char key, int x, int y);
	void Mouse(int button, int state, int x, int y);
	void MouseMove(int x, int y);
	void Resize(int width, int height);
	void Spawn();
	void Aktualizuj();
	void Przegrana();


};

extern cScene scena;

