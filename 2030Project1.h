// COSC 2030
// Project 1
// @author Tamara Linse
// @date 10.25.2018
// @file 2030Project1.h

// Project 1, Blood Sugar, inputs multiple daily blood sugar readings over the course of two weeks
// and outputs daily and weekly sums, maxes, mins, and counts, as well as the highest weekly delta.

#ifndef PROJ1_H_
#define PROJ1_H_

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <array>
#include <sstream>

using namespace std;

class BloodSugar
{

private:

	typedef list<float> bloodSugar;    // a list of blood sugar readings each day
	typedef bloodSugar twoWeeks[14];   // an array of lists containing two weeks of data

	bloodSugar bs;
	twoWeeks tw;
	float dailySum[14] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	float dailyMax[14] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	float dailyMin[14] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int dailyCount[14] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

	float weeklySum[2] = { 0,0 };
	float weeklyMax[2] = { 0,0 };
	float weeklyMin[2] = { 0,0 };
	int weeklyCount[2] = { 0,0 };

	float weeklyDelta[6] = { 0,0,0,0,0,0 };
	int maxDelta = 0;

	int countW1 = 0;
	int countW2 = 0;

public:

	BloodSugar();
	~BloodSugar();
	void processData(float input, int day);
	void dailySummary(int day);
	void weeklySummary(int day);
	float sumPerDay(int &day);
	float maxPerDay(int &day);
	float minPerDay(int &day);
	int countPerDay(const int &day);
	float sumPerWeek(int &d, int &week);
	float maxPerWeek(int &week);
	float minPerWeek(int &week);
	int countPerWeek(int &week);
	int dayDelta(int &day, int &week);
	bool isFloat(const string &in);
	void outputData(int &d);

};


#endif