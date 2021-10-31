#include "RunPerformance.h"

namespace RUN
{
	void RunPerformance::Info()
	{
		cout << "\n*Info:\n";
		std::cout << "Marathon:\t" << Distances::Marathon << "\tkm" << endl;
		std::cout << "Half Marathon:\t" << Distances::HMarathon << "\tkm" << endl;
		std::cout << "Ten Kilomiters:\t" << Distances::TenKm << "\tkm" << endl;
		std::cout << "Five Kilomiters:" << Distances::FiveKm << "\tkm" << endl;

	}
	void RunPerformance::PrintData()
	{
		cout << "\n*Your Data:\n";
		cout << "Distance:\t" << Data.distance;
		
		if (Data.distance == Distances::Marathon)
		{
			cout << "'Marathon'";
		}
		if (Data.distance == Distances::HMarathon)
		{
			cout << "'Half Marathon'";
		}
		cout << "\nPace:\t\t" << Data.pace[clock::min] << ':'<< Data.pace[clock::sec] << endl;
		cout << "Time:\t\t" << Data.time[clock::hour] << ':' << Data.time[clock::min] << ':' << Data.time[clock::sec] << endl;
	}
	void RunPerformance::EditDataDistance()
	{
		string row;
		bool triger = false;
		//this->PrintData();
		cout << "\nChange Distance: " << Data.distance << "  to ";
		
		while (triger != true)
		{
			try
			{
				cin >> row;
				size_t i = 0;
				for (; i < row.length(); i++)
				{
					if (isdigit(row[i]))
					{
						triger = true;
						row = row.substr(i, row.length() - i);
						Data.distance = stod(row);
						break;
					}
				}
				if (triger == false && (row == "Marathon" || row == "HMarathon"))
				{
					triger = true;
					if (row == "Marathon") Data.distance = Distances::Marathon;
					if (row == "HMarathon") Data.distance = Distances::HMarathon;
				}
				if (Data.distance == 42)Data.distance = Distances::Marathon;
				if (Data.distance == 21)Data.distance = Distances::HMarathon;
				if (triger == false)
				{
					cout << "Wrong enter, try one more time: ";
				}
			}
			catch(exception & ex)
			{
				cout << ex.what() << endl;
				cout << "Program catched the exception!\n Repeat enter: ";
			}
		}

	}

	void RunPerformance::EditDataPace()
	{
		string row;
		bool triger = false;
		cout << "Change pace from " << Data.pace[clock::min] << ':' << Data.pace[clock::sec] << "  (min:sec): ";
		while (triger == false)
		{
			try
			{
				cin >> row;
				size_t i = 0;
				size_t point = 0;
				for (; i < row.size(); i++)
				{
					//cout << row[i] << i << endl;;
					if ((row[i] == ':' || row[i] == '.' || row[i] == '/') && i < 3)
					{
						point = i;
						Data.pace[clock::min] = stod(row.substr(0, point));
						Data.pace[clock::sec] = stod(row.substr(point + 1, row.size()));
						if (Data.pace[clock::sec] < 10 && row[point + 1] != '0')Data.pace[clock::sec] *= 10;
						triger = true;
						break;
						
					}
				}
				if (triger != true) cout << "-Wrong enter try one more time: ";
				if (Data.pace[clock::min] > Clocks::Minute || Data.pace[clock::sec] > Clocks::Minute)
				{
					triger = false;
					Data.pace[clock::min] = 0;
					Data.pace[clock::sec] = 0;
					throw exception("Seconds or minutes biget then 60");
				}

			}
			catch(exception & ex)
			{
				cout << ex.what() << endl;
				cout << "-Wrong enter try one more time: ";
			}
		}
	}

	void RunPerformance::EditDataTime()
	{
		string row;
		bool triger = false;
		cout << "Change time from " << Data.time[clock::hour] << ':' << Data.time[clock::min] << ':' << Data.time[clock::sec] << " to (hour:minutes:seconds): ";

		while (triger == false)
		{
			try
			{
				size_t ione = 0;
				size_t itwo = 0;
				cin >> row;
				for (; itwo < row.size(); itwo++)
				{
					//cout << itwo << " - " << row[itwo] << endl;
					if ((row[itwo] == ':' || row[itwo] == '.' || row[itwo] == '/') && ione == 0 && itwo < 3) ione = itwo;
					if (ione != 0 && (row[itwo] == ':'|| row[itwo] == '.' || row[itwo] == '/') && (itwo - ione) <= 3 && itwo > ione  && (row.size() - itwo) <= 3)          
					{
						Data.time[clock::hour] = stod(row.substr(0, ione));
						Data.time[clock::min] = stod(row.substr(ione + 1, itwo - 2));
						Data.time[clock::sec] = stod(row.substr(itwo + 1, itwo + 1));
						//if (Data.time[clock::min] < 10 && row[point + 1] != '0')Data.pace[clock::sec] *= 10;
						//if (Data.time[clock::sec] < 10 && row[point + 1] != '0')Data.pace[clock::sec] *= 10;
						triger = true;
						break;
					}
				}
				if (triger != true) cout << "\nWrong enter, try one more time: ";
				if (Data.time[clock::min] > Clocks::Minute || Data.time[clock::sec] > Clocks::Minute)
				{
					triger = false;
					Data.time[clock::min] = 0;
					Data.time[clock::sec] = 0;
					throw exception("Seconds or minutes biget then 60");
				}
			}
			catch (const std::exception& ex)
			{
				cout << ex.what();
				cout << "\nCatched the exception, repeat enter: ";
			}

		}

		//write limites for pace and correct data for time!
	}


}