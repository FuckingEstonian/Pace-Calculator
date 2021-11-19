#pragma once
#include <sstream>
#include"RunData.h"
#include "Constants.h"
namespace RUN
{
	class RunPerformance
	{
	private:
	
		RunData Data;
		 
	public:
		 //RunPerformance ();
		~RunPerformance() { cout << "Destructor for User" << endl; };

		void Info();
		void PrintData();
		void MainMenu();

		void EditDataDistance();
		void EditDataPace();
		void EditDataTime();

		void CalculateDistance();
		void CalculatePace();
		void CalculateTime();

		bool Check(); /// to check that all data is entered
		RunData& list();
	
	};
}