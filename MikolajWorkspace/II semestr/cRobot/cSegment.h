#pragma once
#include <iostream>
#include <GL/freeglut.h>
#include <windows.h>

class cSegment
{
private:
	float width, height;
	float x, y;
	float R, G, B;
	float alpha;

public:
	cSegment();
	cSegment(float a, float b);
	
	void SetX(float a);
	void SetY(float a);
	void SetAlpha(float a);
	
	float GetX();
	float GetY();
	float GetAlpha();

	void Move(float a, float b);
	void MoveTo(float a, float b);
	void Draw();
	void Rotate(float alpha);
	void RotateTo(float alpha);
	void SetColor(float a, float b, float c);

};
