#pragma once
#include <vector>
#include "UR3Message.h"
#include <string>
class UR3MessageOut;
using namespace std;
class UR3Intermediator
{

public:

	bool Connect();

	vector<int> ReadDataFlow();
	
	bool SendData(string ParsedToStringMethod);
	string ParseOutput(UR3MessageOut MessageToSend);

	void LogData(string data);
	void ViewData();
	UR3Message DecipherMessage(const vector<int>& DataFlow);

	volatile vector<int> DataFlow;


	



};

