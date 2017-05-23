#pragma once
#include <vector>
using namespace std;
class UR3MessageOut
{
public:

	vector<double> JointsPositions;
	double Acceleration;
	double Speed;
	double BlendRadius;
	double Time;

	UR3MessageOut();
	UR3MessageOut(const vector<double> jointsPositionsList, double acceleration, double speed, double blendRadius, double time);
	~UR3MessageOut();
};

