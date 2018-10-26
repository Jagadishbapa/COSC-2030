// COSC 2030
// Project 1
// @author Tamara Linse
// @date 10.25.2018
// @file 2030Project1.h

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
	float dailySum[14];
	float dailyMax[14];
	float dailyMin[14];
	int dailyCount[14];

	float weeklySum[2];
	float weeklyMax[2];
	float weeklyMin[2];
	int weeklyCount[2];

	float weeklyDelta[6];

public:

	void processData(float input, int day);
	void dailySummary(int day);
	void weeklySummary(int day);
	void nextDay();
	float sumPerDay(int &day);
	float maxPerDay(int &day);
	float minPerDay(int &day);
	int countPerDay(const int &day);
	float sumPerWeek(int &week);
	float maxPerWeek(int &week);
	float minPerWeek(int &week);
	int countPerWeek(int &week);
	int dayDelta(int &day);
	bool isFloat(const string &in);

};


#endif