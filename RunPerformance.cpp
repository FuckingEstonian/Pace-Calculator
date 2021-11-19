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
		cout << "\nPace:\t\t" << Data.pace[clock::min] << ':' << Data.pace[clock::sec] << endl;
		cout << "Time:\t\t" << Data.time[clock::hour] << ':' << Data.time[clock::min] << ':' << Data.time[clock::sec] << endl;
	}

	void RunPerformance::MainMenu()
	{
		bool triger = false;
		string kword = "Nothing";
		while (kword != "exit")
		{
			cout << "\nTo see commands:\t command" << endl;
			this->PrintData();
			
			cin >> kword;
			system("cls");

			if (kword == "command")
			{
				cout << "\nTo see info:\t\t Info";
				cout << "\nTo see race data:\t Data" << endl;

				cout << "\nTo edit distance:\t EDist";
				cout << "\nTo edit pace:\t\t EPace";
				cout << "\nTo edit time:\t\t ETime";

				cout << "\n\nTo calculate distance:\t CDist";
				cout << "\nTo calculate pace:\t CPace";
				cout << "\nTo calculate time:\t CTime";
				triger = true;
			}

			if (kword == "Info") { this->Info(); triger = true; }
			if (kword == "Data") { this->PrintData(); triger = true; }
			if (kword == "EDist") { this->EditDataDistance(); triger = true; }
			if (kword == "EPace") { this->EditDataPace(); triger = true; }
			if (kword == "ETime") { this->EditDataTime(); triger = true; }
			if (kword == "CDist") { this->CalculateDistance(); triger = true; }
			if (kword == "CPace") { this->CalculatePace(); triger = true; }
			if (kword == "CTime") { this->CalculateTime(); triger = true; }

			if (triger != true) cout << "\nInvalid enter, try one more time." << endl;
			triger = false;
		}
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
						if (Data.distance < 0) Data.distance *= -1;
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
			catch (exception& ex)
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
						for (short j = 0; j <= clock::min; j++)
						{
							if (Data.pace[j] < 0) Data.pace[j] *= -1;
						}
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
			catch (exception& ex)
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
					if (ione != 0 && (row[itwo] == ':' || row[itwo] == '.' || row[itwo] == '/') && (itwo - ione) <= 3 && itwo > ione && (row.size() - itwo) <= 3)
					{
						Data.time[clock::hour] = stod(row.substr(0, ione));
						Data.time[clock::min] = stod(row.substr(ione + 1, itwo - 2));
						Data.time[clock::sec] = stod(row.substr(itwo + 1, itwo + 1));
						for (short j = 0; j <= clock::hour; j++)
						{
							if (Data.time[j] < 0) Data.time[j] *= -1;
						}
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

	}

	void RunPerformance::CalculateDistance()
	{

		try
		{
			if (Data.pace[clock::min] == 0 || (Data.time[clock::hour] == 0 && Data.time[clock::min] == 0))
			{
				throw exception("Nod relevant data in fields 'Time' and 'Pace'");
			}

			Data.distance = ((Data.time[clock::hour] * Clocks::Hour) + (Data.time[clock::min] * Clocks::Minute) + Data.time[clock::sec])
				/ ((Data.pace[clock::min] * Clocks::Minute) + Data.pace[clock::sec]);

		}
		catch (const exception& ex)
		{
			cout << ex.what();
			cout << "\nCalcDistance exception!" << endl;
		}

	}

	void RunPerformance::CalculatePace()
	{
		short first, second;
		try
		{
			if (Data.distance == 0 || (Data.time[clock::hour] == 0 && Data.time[clock::min] == 0))
			{
				throw exception("Nod relevant data in fields 'Time' and 'Distance'");
			}

			first = (((Data.time[clock::hour] * Clocks::Hour) + (Data.time[clock::min] * Clocks::Minute) + Data.time[clock::sec])
				/ Data.distance) / Clocks::Minute;

			second = (int)(((Data.time[clock::hour] * Clocks::Hour) + (Data.time[clock::min] * Clocks::Minute) + Data.time[clock::sec])
				/ Data.distance) % (int)Clocks::Minute;

			Data.pace[clock::min] = first;
			Data.pace[clock::sec] = second;

		}
		catch (const std::exception& ex)
		{
			cout << ex.what();
			cout << "\CalcPace exception!" << endl;
		}
	}

	void RunPerformance::CalculateTime()
	{
		short first, second, third;

		try
		{

			if (Data.distance == 0 || (Data.pace[clock::min] == 0 && Data.pace[clock::sec] == 0))
			{
				throw exception("Nod relevant data in fields 'Pace' and 'Distance'");
			}

			Data.time[clock::hour] =(short)((short)(((Data.pace[clock::min] * Clocks::Minute) + Data.pace[clock::sec]) * Data.distance) / Clocks::Hour);
			Data.time[clock::min] = (short)(((short)(((Data.pace[clock::min] * Clocks::Minute) + Data.pace[clock::sec]) * Data.distance) % (short)Clocks::Hour) / (short)Clocks::Minute);
			Data.time[clock::sec] = (short)(((short)(((Data.pace[clock::min] * Clocks::Minute) + Data.pace[clock::sec]) * Data.distance) % (short)Clocks::Hour) % (short)Clocks::Minute);

		}
		catch (const std::exception& ex)
		{
			cout << ex.what();
			cout << "\CalcPace exception!" << endl;
		}
	}

	bool RunPerformance::Check()
	{
		if (Data.distance == 0 || (Data.pace[clock::min] == 0 && Data.pace[clock::sec] == 0)
			|| (Data.time[clock::hour] == 0 && Data.time[clock::min] && Data.time[clock::sec] == 0))
		{
			return false;
		}
		else
		{
			return true;
		}

	}

	RunData& RunPerformance::list()
	{
		if (this->Check() != true)
		{
			cout << "List not created.\nNo relevant data!" << endl;
			return;
		}

		short laps;

		if (Data.distance == Distances::Marathon || Data.distance == Distances::HMarathon) laps = (short)Data.distance + 1;
		else laps = (short)Data.distance;
		// needs to write stuct which will use laps for constructor to create list of elements
		// don't forget about destructor;

		// use RunData to create linked list and use link on it to print it and save it

		// create inheritance for RunData with exta fields
		// - string (for remarks)
		// - char	(for file input)
		// - bool	(to track changes in table)
		
		RunDataTable Table(Data.distance,Data.pace[clock::min],Data.pace[clock::sec],Data.time[clock::hour], Data.time[clock::min], Data.time[clock::sec]);
		RunDataTable* mark = & Table;
		RunDataTable* nod = mark;
		double TT, Th, Tm, Ts; // use this for time

		for (short i = 1; i <= laps; i++)
		{
			TT = ((Data.pace[clock::min] * Clocks::Minute) + Data.pace[clock::sec]) * i;
			//Th = (short)(TT / Clocks::Hour);
			//Tm = (short)(TT / Clocks::Minute) - Th * Clocks::Minute;
			//Ts = (short)((short)TT % (short)(TT / Clocks::Minute));
			// for testing

			mark->distance = i;
			mark->pace[clock::min] = Data.pace[clock::min];
			mark->pace[clock::sec] = Data.pace[clock::sec];
			
			if (mark->previous == NULL) // may be don't need
			{ 
				mark->time[clock::hour] = 0;
				mark->time[clock::min] = Data.pace[clock::min];
				mark->time[clock::sec] = Data.pace[clock::sec];
			}
			else
			{
				mark->time[clock::hour] = (short)(TT / Clocks::Hour);
				mark->time[clock::min] = (short)(TT / Clocks::Minute) - Th * Clocks::Minute;
				mark->time[clock::sec] = (short)((short)TT % (short)(TT / Clocks::Minute));
			}

			nod = new RunDataTable;
			nod->previous = mark;
			mark->next = nod;
			mark = nod;


		}

	}

}