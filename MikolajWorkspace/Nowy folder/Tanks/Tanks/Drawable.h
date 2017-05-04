#pragma once
#include<GL\freeglut.h>
#include <math.h>
#include <windows.h>
#include <vector>

struct Perimeter {
	float xa;
	float xb;
	float ya, yb;
};

class Drawable
{
protected:
	float x, y;
	Perimeter perimeter;
	float alpha;
	float v;
	float vAlpha;

	int time;

	bool visible;

public:
	Drawable();
	//Drawable(float x, float y, float v, float vAlpha);
	virtual void Draw() = 0;
	void MoveUp();
	void MoveDown();
	void MoveTo(float x, float y);
	void Rotate(float alpha);
	void RotateTo(float alpha);

	float GetX() { return this->x; }
	float GetY() { return this->y; }
	float GetAlpha() { return this->alpha; }

	void SetX(float x) { this->x = x; }
	void SetY(float y) { this->y = y; }

	void SetSpeed(float v, float alpha) { this->v = v; this->vAlpha = alpha; }

	void Update(int currentTime);

	bool GetVisible() { return this->visible; }
	void SetPerimeter(float xa, float ya, float xb, float yb) { this->perimeter.xa = xa; this->perimeter.xb = xb; this->perimeter.ya = ya; this->perimeter.yb = yb; }
	void Collision(Drawable&X);
	inline void Reset() { this->time = GetTickCount(); }
	~Drawable();
};


