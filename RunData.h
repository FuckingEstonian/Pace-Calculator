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

	RunData(double Distance = 0, double Pace = 0, double Time = 0)
		:distance(Distance), pace{ Pace,Pace }, time { Time,Time,Time }, next(NULL), previous(NULL) {};
	~RunData() { cout << "Destructor for Data" << endl; };
};

