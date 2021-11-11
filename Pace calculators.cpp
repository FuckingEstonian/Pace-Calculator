#include <conio.h>
#include <iostream>
#include "RunPerformance.h"
using namespace std;
using namespace RUN;

int main()
{
    RunPerformance Athlete;
    Athlete.Info();
    Athlete.PrintData();

    Athlete.EditDataTime();
    Athlete.EditDataDistance();
    Athlete.CalculatePace();
    
    Athlete.PrintData();
    system("pause");

    // HELLO I'M HERE!
    // next step -> time calc and so on...
}
