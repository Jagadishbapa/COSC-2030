// COSC 2030
// Lab 1
// @date 9-17-18
// @author Tamara Linse

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main()
{

	int count = 0;
	string filename, line;
	double current = 0, previous = 0, temp = 0;

	// Get filename
	cout << "Please input filename: ";
	cin >> filename;

	// Open file and process
	ifstream inputFile(filename);
	if (inputFile.is_open())
	{
		// Process each number
		while (inputFile >> current)
		{

			count++;
			if (count == 1)
			{
				cout << "First Number: " << current << endl;
			}
			if (count == 2)
			{
				cout << "Second Number: " << current << endl;
			}
			previous = temp;
			temp = current;
			
		}

		cout << "Second-to-last Number: " << previous << endl;
		cout << "Last Number: " << current << endl;
		cout << "Count: " << count << endl; 

	}

	inputFile.close();

	system("pause");
	return 0;
}
