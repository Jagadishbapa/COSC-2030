// COSC 2030
// Project 1
// @author Tamara Linse
// @date 10.25.2018
// @file 2030Project1.cpp

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

BloodSugar::BloodSugar()
{
	for (int i = 0; i < 14; i++)
	{
		tw[i - 1] = {};
		bloodSugar bsd = tw[i - 1];
		list<float>::iterator it;
		for (it = bsd.begin(); it != bsd.end(); ++it)
		{
			*it = 0;
		}
	}
}

BloodSugar::~BloodSugar()
{
	// nothing
}

void BloodSugar::processData(float in, int d)
{
	tw[d-1].push_back(in);
}

void BloodSugar::dailySummary(int d)
{
	float dMin = 0;
	dailySum[d-1] = sumPerDay(d);
	dailyMax[d-1] = maxPerDay(d);
	dailyMin[d-1] = minPerDay(d);
	dailyCount[d-1] = countPerDay(d);
	cout << endl;
	cout << "----------------------Daily Summary-----------------------" << endl << endl;
	cout << "  Day of the two-week period:\t\t\t" << d << endl;
	cout << "  Sum of all blood sugar readings:\t\t" << dailySum[d-1] << endl;
	cout << "  Max of all blood sugar readings:\t\t" << dailyMax[d-1] << endl;
	if (dailyMin[d - 1] == INFINITY) { dMin = 0; } else { dMin = dailyMin[d - 1]; }
	cout << "  Min of all blood sugar readings:\t\t" << dMin << endl;
	cout << "  Count of all blood sugar readings:\t\t" << dailyCount[d-1] << endl << endl;
	cout << "----------------------------------------------------------" << endl << endl;

}

void BloodSugar::weeklySummary(int d)
{
	float wMin = 0;
	int w;
	if (d > 7) { w = 2; } else { w = 1; }

	weeklySum[w-1] = sumPerWeek(d, w);
	weeklyMax[w-1] = maxPerWeek(w);
	weeklyMin[w-1] = minPerWeek(w);
	weeklyCount[w-1] = countPerWeek(w);
	maxDelta = dayDelta(d, w);
	cout << endl;
	cout << "----------------------Weekly Summary----------------------" << endl << endl;
	cout << "  Day of the two-week period:\t\t\t" << d << endl;
	cout << "  Week of the two-week period:\t\t\t" << w << endl;
	cout << "  Sum of all blood sugar readings:\t\t" << weeklySum[w-1] << endl;
	cout << "  Max of all blood sugar readings:\t\t" << weeklyMax[w-1] << endl;
	if (weeklyMin[w - 1] == INFINITY) { wMin = 0; } else { wMin = weeklyMin[w - 1]; }
	cout << "  Min of all blood sugar readings:\t\t" << wMin << endl;
	cout << "  Count of all blood sugar readings:\t\t" << weeklyCount[w-1] << endl;
	cout << "  Day of the week with the biggest delta:\t" << maxDelta << endl << endl;
	cout << "----------------------------------------------------------" << endl << endl;

}

float BloodSugar::sumPerDay(int &d)
{
	float sum = 0;
	bloodSugar bsd = tw[d-1];
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
	bloodSugar bsd = tw[d-1];
	list<float>::iterator it;
	for (it = bsd.begin(); it != bsd.end(); ++it)
	{
		if (max < *it) { max = *it; }
	}
	return max;
}

float BloodSugar::minPerDay(int &d)
{
	bloodSugar bsd = tw[d-1];
	float min = INFINITY;
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
	bloodSugar bsd = tw[d-1];
	list<float>::iterator it;
	for (it = bsd.begin(); it != bsd.end(); ++it)
	{
		count++;
	}
	return count;

}

float BloodSugar::sumPerWeek(int &d, int &w)
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
	float tempMax = 0;
	if (w == 1)
	{
		for (int i = 1; i <= 7; i++)
		{
			tempMax = maxPerDay(i);
			if (tempMax > max) { max = tempMax; }
		}
	}
	if (w == 2)
	{
		for (int i = 8; i <= 14; i++)
		{
			tempMax = maxPerDay(i);
			if (tempMax > max) { max = tempMax; }
		}
	}
	return max;
}

float BloodSugar::minPerWeek(int &w)
{
	float min = INFINITY;
	float tempMin = 0;
	if (w == 1)
	{
		for (int i = 1; i <= 7; i++)
		{
			tempMin = minPerDay(i);
			if (tempMin < min) { min = minPerDay(i); }
		}
	}
	if (w == 2)
	{
		for (int i = 8; i <= 14; i++)
		{
			tempMin = minPerDay(i);
			if (tempMin < min) { min = minPerDay(i); }
		}
	}
	return min;
}

int BloodSugar::countPerWeek(int &w)
{
	if (w == 1)
	{
		int countW1 = 0;
		for (int i = 1; i <= 7; i++)
		{
			countW1 += countPerDay(i);
		}
		return countW1;
	}
	else
	{
		countW2 = 0;
		for (int i = 8; i <= 14; i++)
		{
			countW2 += countPerDay(i);
		}
		return countW2;
	}
}

int BloodSugar::dayDelta(int &d, int &w)
{
	if (d == 8) { return 0; }
	int dd[6] = { 0,0,0,0,0,0 };
	int max = 0, maxD = 0;
	if (w == 1)
	{
		for (int i = 2; i <= 7; i++)
		{
			dd[i-2] = countPerDay(i) - countPerDay(i-1);
		}
	}
	else if (w == 2)
	{
		for (int i = 9; i <= 14; i++)
		{
			dd[i-2] = countPerDay(i) - countPerDay(i-1);
		}
	}

	for (int i = 0; i < 6; i++)
	{
		if (max < dd[i]) { max = dd[i]; maxD = i; }
	}
	return maxD;
}

// isFloat() from https://www.quora.com/How-can-I-check-if-a-std-string-is-a-floating-point-number-in-C++

bool BloodSugar::isFloat(const string &in)
{
	stringstream str(in);
	float f;
	return bool(str >> f);
}

/* I ran out of time to complete the functions for floats that are larger than 32 bits
*  or -3.4E+38 to +3.4E+38.  My plan was to have two arrays and implement my own form of
*  scientific notation.  23,005,369, for example.  The first array would carry the '
*  significand/coefficient (2.30), and the second array would carry the power term (-7, 
*  which would represent "x 10 ^ -7").  Addition would be accomplished the same way as 
*  scientific notation:  The significand array numbers would be adjusted so that the powers  
*  were the same and then the significands would be added and then the sum and its
*  power would be adjusted to normalize. Subtraction would be similar. Multiplication
*  would be achieved by multiplying the significands and adding the exponents, then normalizing.
*  Division would be similar, but divided and the exponents would be subtracted. My two arrays would be
*  floats called sig and power. They would be displayed either "cout << sig[i] << " x 10^" << power[i]"
*  or "cout << sig[i] << "E" << power[i]". If I can have more time and it would add to my grade, I would
*  develop this part as well.
*	   
*/
