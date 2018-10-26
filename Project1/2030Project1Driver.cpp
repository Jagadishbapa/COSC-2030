// COSC 2030
// Project 1
// @author Tamara Linse
// @date 10.25.2018
// @file 2030Project1Driver.cpp

// Project 1, Blood Sugar, inputs multiple daily blood sugar readings over the course of two weeks
// and outputs daily and weekly sums, maxes, mins, and counts, as well as the highest weekly delta.

#include <iostream>
#include <cmath>
#include <stack>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include "2030Project1.h"

using namespace std;

int main()
{
	string input;
	int day = 1;
	BloodSugar bs;

	cout << "*************BLOOD SUGAR MONITOR*************" << endl << endl;
	while (input != "Q" || input != "Quit")
	{
		cout << "Enter blood sugar level or 'M' for menu of input options: " << endl;
		cin >> input;
//		if (!(stof(input) <= 0))
//		{
			if (input == "M" || input == "m")
			{
				cout << "'D' or 'Day' = daily summary\n'W' or 'Week' = weekly summary\n'Q' or 'Quit' = quit\n" << endl;
			}
			else if (input == "D" || input == "d" || input == "Day")
			{
				bs.dailySummary(day);
			}
			else if (input == "W" || input == "w" || input == "Week")
			{
				bs.weeklySummary(day);
			}
			else if (input == "N" || input == "n" || input == "Next")
			{
				day++;
				bs.nextDay();
			}
			else if (input == "Q" || input == "q" || input == "Quit")
			{

			}
			else if (bs.isFloat(input))
			{
				bs.processData(stof(input), day);
			}
			else
			{
				// do nothing
			}
//		}
	}
	
	cout << "Thank you for taking care of your health!" << endl;

	system("pause");
	return 0;
}
