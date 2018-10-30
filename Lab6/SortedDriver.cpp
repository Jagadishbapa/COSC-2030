// @author Tamara Linse
// @date 10.29.2018

// SortedDriver.cpp

// tom bailey   1445  25 mar 2014
// Construct sorted sequences and call functions that
//   process the sorted sequences.


#include "RandomUtilities.h"
#include "ContainerPrinting.h"
#include "winTimer.h"//CHANGE: this to unixTimer.h if on mac/linux
#include <list>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// post: a sorted vector of listSize random doubles from
//         the range minNum to maxNum has been returned.

vector<double> getNums(size_t listSize, double minNum, double maxNum)
{
	vector<double> theList;
	for (size_t i = 0; i < listSize; ++i)
	{
		theList.push_back(randReal(minNum, maxNum));
	}

	sort(begin(theList), end(theList));

	return theList;
}


// post: a sorted list of numWords words of length
//         wordLength with characters chosen randomly from
//         alphabet has been returned.

list<string> getWords(size_t numWords, size_t wordLength, string alphabet)
{
	list<string> theWords;
	for (size_t i = 0; i < numWords; ++i)
	{
		string word;
		for (size_t j = 0; j < wordLength; ++j)
		{
			word += alphabet.at(randInt(0, alphabet.size()));
		}
		theWords.push_back(word);
	}

	theWords.sort();

	return theWords;
}


// pre:  number is not empty;
//       number is sorted from smallest to largest
// post: The most isolated entry in number has been returned

double mostIsolated(vector<double> & number)
{
	if (number.empty()) { return 0; }
	double mIsol = number[0];
	const int size = number.size();
	vector<double> eachDiff (number.begin(), number.end());
	for (int h = 0; h < size; h++) { eachDiff[h] = 0; }
	eachDiff[0] = abs(number[1] - number[0]);
	cout << "eachDiff[0] = " << eachDiff[0] << endl;
	for (int i = 1; i <= size-2; i++)
	{
		double d1 = 0, d2 = 0;
		d1 = abs(number[i] - number[i - 1]);
		d2 = abs(number[i + 1] - number[i]);
		if (d1 > d2)
		{
			eachDiff[i] = d1;
		}
		else
		{
			eachDiff[i] = d2;
		}
		cout << "eachDiff[i] = " << eachDiff[i] << endl;
	}

	eachDiff[size - 1] = abs(number[size - 1] - number[size - 2]);
	cout << "eachDiff[size-1] = " << eachDiff[size - 1] << endl;

	for (int j = 0; j < size - 2; j++)
	{
		if (eachDiff[j] < eachDiff[j + 1])
		{
			mIsol = number[j + 1];
		}
	}
	cout << "mIsol = " << mIsol << endl;
	return mIsol;
}


// pre:  A and B are sorted.
// post: The number of strings in A that do not occur in B
//         has been returned.

int unmatched(list<string> & A, list<string> & B)
{
	// STUB  STUB  STUB
	return -1;
}


int main()
{
	cout << "Find the most isolated number" << endl
		<< "-----------------------------" << endl << endl;
	while (true)
	{
		cout << "Enter the size of the list of numbers: ";
		int n = 0;
		cin >> n;
		if (n <= 0)
			break;
		cout << "Enter a seed to generate a random number: ";
		unsigned int seed;
		cin >> seed;
		srand(seed);

		// Construct a sorted list of numbers
		Timer get;
		get.start();
		vector<double> numbers = getNums(n, -n, n);
		get.stop();
		cout << "The sorted list of numbers was constructed in " << get() << " seconds"
			<< endl;

//		if (n < 10)
		cout << numbers << endl << endl;

		// Report a most isolated isolated number
		Timer time;
		time.start();
		double isolated = mostIsolated(numbers);
		time.stop();
		cout << "The most isolated number is "
			<< isolated << endl
			<< "calculated in " << time() << " seconds"
			<< endl << endl;
	}


	cout << endl << endl;
	cout << "Count the unmatched words" << endl
		<< "-------------------------" << endl << endl;
	while (true)
	{
		cout << "Enter size of the list of words: ";
		int n = 0;
		cin >> n;
		if (n <= 0)
			break;
		cout << "Enter the length of the words: ";
		int wordSize;
		cin >> wordSize;
		cout << "Enter the letters that constitute your alphabet: ";
		string alphabet;
		cin >> alphabet;

		cout << "Enter a seed to generate a random number: ";
		unsigned int seed;
		cin >> seed;
		srand(seed);

		// Construct two sorted vectors of words
		Timer get;
		get.start();
		list<string> A = getWords(n, wordSize, alphabet);
		list<string> B = getWords(n, wordSize, alphabet);
		get.stop();
		cout << "The two sorted vectors of words were constructed in " << get() << " seconds"
			<< endl;

		if (wordSize * n < 60)
		{
			cout << "A is: " << A << endl
				<< "B is: " << B << endl;
		}

		// Report the number of words in the first sorted list
		//   that are not in the second sorted list
		Timer time;
		time.start();
		int count = unmatched(A, B);
		time.stop();
		cout << count
			<< " words in A were not in B" << endl
			<< "This was calculated in " << time() << " seconds"
			<< endl << endl;
	}

	system("pause");
	return 0;
}
