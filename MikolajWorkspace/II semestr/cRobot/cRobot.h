#pragma once
#include "cSegment.h"
#include <vector>

class cRobot
{
private:
	std::vector<cSegment> segments;
	int active;
	cSegment platform;
	std::vector<std::vector<float>> map;
	int mapWsk;
	int beginTime;
	bool automove;
public:
	cRobot();
	cRobot(float a, float b);
	void SetAutomove();
	void SetMapWsk();

	float GetPlatformX();
	float GetPlatformY();
	float GetPlatformAlpha();
	
	void Draw();
	void Move(float a, float b);
	void MoveTo(float a, float b);
	void Rotate(float alpha);
	void RotateTo(float alpha);
	void SetColor(float a, float b, float c);
	
	void RotateSegment(float alpha);
	void AddSegment();
	void DeleteSegment();
	void NextSegment();
	void PrevSegment();

	void SavePosition();
	void Update(int time);


};
