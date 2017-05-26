#pragma once
#include <vector>
#include <inttypes.h>


enum RobotMode {
        ROBOT_MODE_DISCONNECTED = 0,
        ROBOT_MODE_CONFIRM_SAFETY = 1,
        ROBOT_MODE_BOOTING = 2,
        ROBOT_MODE_POWER_OFF = 3,
        ROBOT_MODE_POWER_ON = 4,
        ROBOT_MODE_IDLE = 5,
        ROBOT_MODE_BACKDRIVE = 6,
        ROBOT_MODE_RUNNING = 7,
        ROBOT_MODE_UPDATING_FIRMWARE = 8
};

enum ControlMode{
        CONTROL_MODE_POSITION = 0,
        CONTROL_MODE_TEACH = 1,
        CONTROL_MODE_FORCE = 2,
        CONTROL_MODE_TORQUE = 3

};


enum JointMode{
        JOINT_SHUTTING_DOWN_MODE = 236,
        JOINT_PART_D_CALIBRATION_MODE = 237,
        JOINT_BACKDRIVE_MODE = 238,
        JOINT_POWER_OFF_MODE = 239,
        JOINT_NOT_RESPONDING_MODE = 245,
        JOINT_MOTOR_INITIALISATION_MODE = 246,
        JOINT_BOOTING_MODE = 247,
        JOINT_PART_D_CALIBRATION_ERROR_MODE = 248,
        JOINT_BOOTLOADER_MODE = 249,
        JOINT_CALIBRATION_MODE = 250,
        JOINT_FAULT_MODE = 252,
        JOINT_RUNNING_MODE = 253,
        JOINT_IDLE_MODE = 255

};

enum ToolMode{
        TOOL_BOOTLOADER_MODE = 249,
        TOOL_RUNNING_MODE = 253,
        TOOL_IDLE_MODE= 255

};

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

enum SafetyMode{
        SAFETY_MODE_FAULT = 9,
        SAFETY_MODE_VIOLATION = 8,
        SAFETY_MODE_ROBOT_EMERGENCY_STOP = 7,
        SAFETY_MODE_SYSTEM_EMERGENCY_STOP = 6,
        SAFETY_MODE_SAFEGUARD_STOP = 5,
        SAFETY_MODE_RECOVERY = 4,
        SAFETY_MODE_PROTECTIVE_STOP = 3,
        SAFETY_MODE_REDUCED = 2,
        SAFETY_MODE_NORMAL = 1

};

enum RobotMessageType {
        ROBOT_MESSAGE_TEXT = 0,
        ROBOT_MESSAGE_PROGRAM_LABEL = 1,
        PROGRAM_STATE_MESSAGE_VARIABLE_UPDATE = 2,
        ROBOT_MESSAGE_VERSION = 3,
        ROBOT_MESSAGE_SAFETY_MODE = 5,
        ROBOT_MESSAGE_ERROR_CODE = 6,
        ROBOT_MESSAGE_KEY = 7,
        ROBOT_MESSAGE_REQUEST_VALUE = 9,
        ROBOT_MESSAGE_RUNTIME_EXCEPTION = 10
};

class RobotModeData //value 0
{ 
public:
	uint64_t timestamp;
	
	bool isRobotConnected;
	bool isRealRobotEnabled;
	bool isRobotPowerOn;
	bool isEmergencyStopped;
	bool isProtectiveStopped;
	bool isProgramRunning;
	bool isProgramPaused;
	
	RobotMode robotMode;
	ControlMode controlMode;
	
	double speedFraction;
	double speedScaling;
	
	RobotModeData();
	~RobotModeData();
};

class JointData // value 1
{
    public:
	std::vector<double> actualJointPosition;
	std::vector<double> targetJointPosition;
	std::vector<double> actualJointSpeed;
	std::vector<float> actualJointCurrent;
	std::vector<float> actualJointVoltage;
	std::vector<float> actualMotorTemprature;
	
	JointMode jointMode;
	
	~JointData();
};

class ToolData //value 2
{
    public:
	char analogInputRange2;		
	char analogInputRange3;	
	
	double analogInput2;
	double analogInput3;		
	
	float toolVoltage48V;		
	float toolCurrent;		
	float toolTemperature;
	
	unsigned char toolOutputVoltage;				
	
	ToolMode toolMode;	

	ToolData();
	~ToolData();

};

class MasterboardData //value 3
{
    public:
	int digitalInputBits;
	int digitalOutputBits;
	char analogInputRange0;
	char analogInputRange1;
	double analogInput0;
	double analogInput1;
	char analogOutputDomain0;
	char analogOutputDomain1;
	double analogOutput0;
	double analogOutput1;
	float masterBoardTemperature;
	float robotVoltage48V;
	float robotCurrent;
	float masterIOCurrent;
	SafetyMode safetyMode;
	unsigned char masterOnOffState;
	char euromap67InterfaceInstalled;
	int euromapInputBits;
	int euromapOutputBits;
	float euromapVoltage;
	float euromapCurrent;
	
	MasterboardData();
	~MasterboardData();
};

class CartesianInfoData // value 4
{
    public:
	double x,y,z;
	double rx, ry, rz;
	
	CartesianInfoData();
	~CartesianInfoData();
};

class ConfigurationData //value 6
{
    public:
	double jointMinLimit;	
	double jointMaxLimit;	
	double jointMaxSpeed;	
	double jointMaxAcceleration;	
	double vJointDefault;	
	double aJointDefault;	
	double vToolDefault;	
	double aToolDefault;	
	double eqRadius;	
	double DHa;	
	double DHd;	
	double DHalpha;	
	double DHtheta;	
	int masterboardVersion;	
	int controllerBoxType;	
	int robotType;	
	int robotSubType;	
	
	ConfigurationData();
	~ConfigurationData();

};

class UR3Message
{
public:
	
	int MessageSize;
	std::vector<JointData> jointsData;



	UR3Message();
	~UR3Message();
};

