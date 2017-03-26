#pragma once
#include <vector>
#include "Prostokat.h"

class Scena
{
	std::vector<Prostokat> _zbior_Prostokatow;
	int _actual;
public:

	void Init(char* WindowName, int argc, char *argv[]);
	void KeyboardFunctions(unsigned char key, int mouse_x, int mouse_y);
	void DisplayFunction();
	void IdleFunctions();
	void ResizeFunctions(int width, int height);

	Scena();
	~Scena();
};

