#pragma once
#include <sstream>
#include"RunData.h"
#include "Constants.h"
#include <fstream>
namespace RUN
{
	class RunPerformance
	{
	private:
	
		RunData Data;
		 
	public:
		 //RunPerformance ();
		//~RunPerformance() { cout << "Destructor for User" << endl; };

		void Info();
		void PrintData();
		void MainMenu();

		void EditDataDistance();
		void EditDataPace();
		void EditDataPace(RunData&);
		void EditDataTime();
		void EditDataTime(RunData&);

		void CalculateDistance();
		void CalculatePace();
		void CalculateTime();
		void CalculateListDataPace(RunData&);
		void CalculateListDataTime(RunData&);

		bool Check(); /// to check that all data is entered
		void ListHead();
		void ListRecord(RunDataTable&);
		void EditList(RunDataTable&);
		void PrintData(RunData&);
		RunDataTable& list(RunDataTable&);


		
	};
}