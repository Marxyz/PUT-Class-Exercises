#pragma once
#include <iostream>
#include <GL/freeglut.h>


class cRectangle
{
private:
	float height, width,x,y;
	float alpha;
	float R, G, B;
	
public:
	cRectangle();
	cRectangle(float a, float b);
	void Move(float a, float b);
	void MoveTo(float a, float b);
	void Draw();
	void Rotate(float alpha);
	void SetColor(float r, float g, float b);
	void Resize(float a, float b);
	~cRectangle();
};

