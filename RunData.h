#pragma once
#include <iostream>
using namespace std;
enum clock
{
	sec,
	min, 
	hour		
};

class RunData
{
public:
	double distance;
	double pace[2];
	double time[3];

	RunData* next;
	RunData* previous;

	RunData(double Distance = 0, double PaceM = 0, double PaceS = 0, double TimeH = 0, double TimeM = 0, double TimeS = 0)
		:distance(Distance), pace{ PaceM,PaceS }, time { TimeH,TimeM,TimeS }, next(NULL), previous(NULL) {};
	~RunData() { cout << "Destructor for Data" << endl; };
};

class RunDataTable : public RunData
{
public:
	bool changes = false;
	string remark;
	string record;
	
	RunDataTable(double dist = 0, double paceM = 0, double paceS = 0, double timeH = 0, double timeM = 0, double timeS = 0)
		: RunData(dist, paceM, paceS, timeH, timeM, timeS) {};
	~RunDataTable() { cout << "\nDistructor for Table" << endl; };
};

