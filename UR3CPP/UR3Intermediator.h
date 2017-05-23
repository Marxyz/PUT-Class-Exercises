#pragma once
#include <vector>
#include "UR3Message.h"
#include <string>

using namespace std;

class UR3Intermediator
{

public:

	bool Connect();
	vector<int> ReadDataFlow();
	bool SendData(string Method);

	void LogData(string data);
	void ViewData();
 	
	volatile vector<int> DataFlow;


	UR3Message DecipherMessage(const vector<int>& DataFlow);
	


};

