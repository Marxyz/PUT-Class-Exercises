#pragma once
#include "cSegment.h"
#include <vector>
#include "cRobot.h"

class cScene
{
	cRobot robot;
	int active;
	int time1, time2;
public:
	cScene();
	void Init();
	void Draw();
	void Keyboard(unsigned char key, int x, int y);
	void Resize(int width, int height);
	
	void UpdateRobot(int time);

};

extern cScene scena;
