// COSC 2030
// Lab 1
// @date 9/17/18
// @author Tamara Linse

// Purpose: To read in numbers from a file 
// and output number of numbers, first number,
// second number, second-to-last number, and 
// last number.

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	string filename;
	int lineCount = 0, count = 0;
	double firstNum, secondNum, secondLastNum, LastNum;
	ifstream inputFile(filename);
	string line;

//	Input file name

	cout << "Input file name: ";
	cin >> filename;
	cout << endl;

	cout << "The filename is " << filename << endl;

//	Loop to process and output numbers in file

	inputFile.open(filename);

	if (inputFile.is_open()) 
	{

		cout << "Input file is open." << endl;

		// Loop to process each line of test in file

		while (getline(inputFile, line))
		{

	
		}

	}

	inputFile.close();
	cout << "Input file is closed." << endl;

	system("pause");
	return 0;
}

/*

			bool firstNum, secondNum, sToLastNum, lastNum;
			bool fDone = false, sDone = false, sToLastDone = false, lastDone = false;
			double currentNum;
			string currentSNum, tempStr;
			char currentChar, nextChar;

			for (size_t i = 0; i < line.length(); i++)
			{
				currentChar = line[i];
				cout << "Current character: " << currentChar << endl;
				if (!(isspace(currentChar))
				{
					tempStr = currentChar;
					currentSNum = currentSNum.append(tempStr);
				}
			}

			cout << "CurrentSNum: " << currentSNum << endl;

			cout << "Current count of lines is " << lineCount << endl;
			cout << "This line of text reads " << line << endl;
			lineCount++;



for (int i = 0; i < line.length(); i++)
{
	currentChar = line[i];
	previousChar = line[i - 1];
	nextChar = line[i + 1];

	if (!(isspace(currentChar)))
	{
		if (isspace(previousChar) && isspace(nextChar))
		{
			if (firstNum) { cout << line[i]; }
			if (secondNum) { cout << line[i]; }
			if (secondToLastNum) { cout << line[i]; }
			if (lastNum) { cout << line[i]; }

		}
		if (isspace(previousChar) && (!(isspace(nextChar))))
		{
			if (firstNum) { cout << line[i]; }
			if (secondNum) { cout << line[i]; }
			if (secondToLastNum) { cout << line[i]; }
			if (lastNum) { cout << line[i]; }

		}
		if (!(isspace(previousChar)) && (isspace(nextChar))
		{
			if (firstNum) { cout << line[i]; }
			if (secondNum) { cout << line[i]; }
			if (secondToLastNum) { cout << line[i]; }
			if (lastNum) { cout << line[i]; }

		}
	}
	if (firstNum) { cout << line[i]; }
	if (secondNum) { cout << line[i]; }
	if (secondToLastNum) { cout << line[i]; }
	if (lastNum) { cout << line[i]; }



			// Check each character to see if it's a number
/*
			int i = 0;
			char str1[] = "This is an example string.";
			while (str1[i])
			{
				if (!(isspace(str1[i])))
				{
					cout << str1[i];
				}
				i++;
			}
			cout << endl; */

