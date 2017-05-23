#pragma once


enum MessageType
{
	ROBOT_STATE = 16, ROBOT_MESSAGE = 20, PROGRAM_STATE_MESSAGE = 25
};

enum PackageTypes
{
	ROBOT_MODE_DATA = 0,
	JOINT_DATA = 1,
	TOOL_DATA = 2,
	MASTERBOARD_DATA = 3,
	CARTESIAN_INFO = 4,
	KINEMATICS_INFO = 5,
	CONFIGURATION_DATA = 6,
	FORCE_MODE_DATA = 7,
	ADDITIONAL_INFO = 8,
	CALIBRATION_DATA = 9,
	SAFETY_DATA = 10
};




class UR3Message
{
public:
	
	int MessageSize;




	UR3Message();
	~UR3Message();
};

