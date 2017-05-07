#pragma once
#include "Tank.h"
class Scene
{
	std::vector<Drawable*> objects;
	double xmin, xmax, ymin, ymax;
public:
	Scene();
	void Idle();
	void Init();
	void Draw();
	void Keyboard(unsigned char key, int x, int y);
	void Mouse(int button, int state, int x, int y);
	void MouseMove(int x, int y);
	void Resize(int width, int height);
	void Update();
	void Clear();
	~Scene();
};

extern Scene scene;

