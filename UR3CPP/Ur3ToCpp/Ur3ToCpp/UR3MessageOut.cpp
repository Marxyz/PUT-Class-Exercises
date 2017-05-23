#include "UR3MessageOut.h"


UR3MessageOut::UR3MessageOut()
{
}

UR3MessageOut::UR3MessageOut(const vector<double> jointsPositionsList, double acceleration, double speed, double blendRadius, double time)
	:JointsPositions(jointsPositionsList), Acceleration(acceleration), Speed(speed), BlendRadius(blendRadius), Time(time)
{
}


UR3MessageOut::~UR3MessageOut()
{
}
