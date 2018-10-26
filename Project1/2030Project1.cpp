// COSC 2030
// Project 1
// @author Tamara Linse
// @date 10.25.2018
// @file 2030Project1.cpp

#include <iostream>
#include <cmath>
#include <stack>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include "2030Project1.h"

using namespace std;

void BloodSugar::processData(float in, int d)
{
	tw[d].push_back(in);
}

void BloodSugar::dailySummary(int d)
{
	dailySum[d] = sumPerDay(d);
	dailyMax[d] = maxPerDay(d);
	dailyMin[d] = minPerDay(d);
	dailyCount[d] = countPerDay(d);

	cout << "-------------Daily Summary-------------" << endl << endl;
	cout << "Sum of all blood sugar readings:\t" << dailySum[d] << endl;
	cout << "Max of all blood sugar readings:\t" << dailyMax[d] << endl;
	cout << "Min of all blood sugar readings:\t" << dailyMin[d] << endl;
	cout << "Count of all blood sugar readings:\t" << dailyCount[d] << endl;
	cout << "---------------------------------------" << endl << endl;

}

void BloodSugar::weeklySummary(int d)
{
	int w;
	if (d > 7) { w = 2; }
	else { w = 1; }
	weeklySum[w] = sumPerWeek(w);
	weeklyMax[w] = maxPerWeek(w);
	weeklyMin[w] = minPerWeek(w);
	weeklyCount[w] = countPerWeek(w);
	weeklyDelta[d] = dayDelta(d);
	cout << "-------------Weekly Summary-------------" << endl << endl;
	cout << "Sum of all blood sugar readings:\t" << weeklySum[d] << endl;
	cout << "Max of all blood sugar readings:\t" << weeklyMax[d] << endl;
	cout << "Min of all blood sugar readings:\t" << weeklyMin[d] << endl;
	cout << "Count of all blood sugar readings:\t" << weeklyCount[d] << endl;
	cout << "Day of the week with the biggest delta:\t" << weeklyDelta << endl;
	cout << "---------------------------------------" << endl << endl;

}
	
void BloodSugar::nextDay()
{

}


float BloodSugar::sumPerDay(int &d)
{
	float sum = 0;
	bloodSugar bsd = tw[d];
	list<float>::iterator it;
	for (it = bsd.begin(); it != bsd.end(); ++it) 
	{
		sum += *it;
	}
	return sum;
}

float BloodSugar::maxPerDay(int &d)
{
	float max = 0;
	bloodSugar bsd = tw[d];
	list<float>::iterator it;
	for (it = bsd.begin(); it != bsd.end(); ++it)
	{
		if (max < *it) { max = *it; }
	}
	return max;
}

float BloodSugar::minPerDay(int &d)
{
	float min = 0;
	bloodSugar bsd = tw[d];
	list<float>::iterator it;
	for (it = bsd.begin(); it != bsd.end(); ++it)
	{
		if (min > *it) { min = *it; }
	}
	return min;
}

int BloodSugar::countPerDay(const int &d)
{
	int count = 0;
	bloodSugar bsd = tw[d];
	list<float>::iterator it;
	for (it = bsd.begin(); it != bsd.end(); ++it)
	{
		count++;
	}
	return count;

}

float BloodSugar::sumPerWeek(int &w)
{
	float sum = 0;
	if (w == 1)
	{
		for (int i = 0; i < 7; i++)
		{
			sum += sumPerDay(i);
		}
	}
	else
	{
		for (int i = 7; i < 14; i++)
		{
			sum += sumPerDay(i);
		}
	}
	return sum;
}

float BloodSugar::maxPerWeek(int &w)
{
	float max = 0;
	if (w == 1)
	{
		for (int i = 0; i < 7; i++)
		{
			if (max < maxPerDay(i)) { max = maxPerDay(i); }
		}
	}
	else
	{
		for (int i = 7; i < 14; i++)
		{
			if (max < maxPerDay(i)) { max = maxPerDay(i); }
		}
	}
	return max;
}

float BloodSugar::minPerWeek(int &w)
{
	float min =0;
	if (w == 1)
	{
		for (int i = 0; i < 7; i++)
		{
			if (min > minPerDay(i)) { min = minPerDay(i); }
		}
	}
	else
	{
		for (int i = 7; i < 14; i++)
		{
			if (min > minPerDay(i)) { min = minPerDay(i); }
		}
	}
	return min;
}

int BloodSugar::countPerWeek(int &w)
{
	int count = 0;
	if (w == 1)
	{
		for (int i = 0; i < 7; i++)
		{
			count += countPerDay(i);
		}
	}
	else
	{
		for (int i = 7; i < 14; i++)
		{
			count += countPerDay(i);
		}
	}
	return count;
}

int BloodSugar::dayDelta(int &d)
{
	int w = 0;
	if (d > 7) { w = 2; }
	else { w = 1; }

	int dd[6];
	int maxD = 0;
	if (w == 1)
	{
		for (int i = 1; i < 7; i++)
		{
			dd[i] = countPerDay(i) - countPerDay(i-1);
		}
	}
	else
	{
		for (int i = 8; i < 14; i++)
		{
			dd[i] = countPerDay(i) - countPerDay(i-1);
		}
	}

	for (int i = 0; i < 6; i++)
	{
		if (maxD < dd[i]) { maxD = dd[i]; }
	}

	return maxD;
}

// From https://www.quora.com/How-can-I-check-if-a-std-string-is-a-floating-point-number-in-C++

bool BloodSugar::isFloat(const string &in)
{
	stringstream str(in);
	float f;
	return bool(str >> f);
}
				

