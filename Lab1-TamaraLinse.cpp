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
	double current = 0, previous = 0, first, second, secondToLast, last;

	// Get filename
	cout << "Please input filename: ";
	cin >> filename;

	// Open file and process
	ifstream inputFile(filename);
	inputFile.open(filename);

	if (inputFile.is_open())
	{
		// Process each line
		while (getline(inputFile, line))
		{

//		while ((!inputFile.eof()) || (!inputFile.fail()))
//		{
//			inputFile.getline(cin, line);

			// Process each token on the line
			for (size_t i = 0; i < line.length(); i++)
			{
				// If it's a one-digit number
				if (isspace(line[i - 1]) && !(isspace(line[i] && (isspace(line[i + 1])))))
				{
					current = double(line[i]);
					count++;
				}
				// If it's the first digit
				else if (isspace(line[i - 1]) && !(isspace(line[i])))
				{
					current = double(line[i]);
				}
				// If it's after the first digit
				else if (!(isspace(line[i - 1])) && !(isspace(line[i])))
				{
					current = double(line[i - 1]) * 10 + double(line[i]);
				}
				// If it's the last digit
				else if (!(isspace(line[i - 1])) && !(isspace(line[i])) && (isspace(line[i + 1])))
				{
					current = double(line[i - 1]) * 10 + double(line[i]);
					count++;
				}
				// If it's a space, do nothing

				// Set variables first and second and set previous to current when needed
				if (count == 1)
				{
					first = current;
					previous = current;
				}
				else if (count == 2)
				{
					second = current;
					previous = current;
				}
			}

			// Output varibles first and second
			if (count >= 2)
			{
				cout << "First number: " << previous << endl;
				cout << "Second number: " << current << endl;
			}
		}

		// Set and output second to last, last, and count
		secondToLast = previous;
		last = current;

		cout << "Second-to-last number: " << secondToLast << endl;
		cout << "Last number: " << last << endl;
		cout << "Count: " << count << endl;

		if (inputFile.fail())
		{
//			cout << "Error reading input file" << strerror_s(errno) << endl;
		}
	}

	inputFile.close();

	system("pause");
	return 0;
}







/*


			// **
			// process through whitespace
			// when another num
			// previous = current
			// loop, while a num
			current = atof(line[i - 1]) * 10 + atof(line[i]);
			cout << "Last number: " << current << endl;
			count++;
			// **
			// repeating ** to **, setting current to previous and current


while (getline(cin, line))
			{
				if (line.compare("") == 0) {
				}
				if (line.at(0).compare(" ") == 0) {
					bool containsToken = false;
					for (auto it = str.begin(); it < str.end(); ++it) {
						if (it.compare(" " != 0) {
							containsToken = true;
						}
						if (containsToken) {
							string currentSNum;
							bool foundFirst = false, foundSecond = false;
							while (getline(cin, line)) {
								while (!foundFirst) {
									while (!foundSecond) {

									}
								}

								size_type pos;
								pos = line.find(' ', 0);
								string rest = line.substr(pos + 1);
								string line = first.substr(0, pos);

								cout << "The first number in " + filename + " is " + first1 << endl;
								cout << "The second number in " + filename + " is " + first2 << endl;



								size_t pos = 0;
								std::string token;
								while ((pos = s.find(delimiter)) != std::string::npos) {
									token = s.substr(0, pos);
									std::cout << token << std::endl;
									s.erase(0, pos + delimiter.length());
								}
							}

							// read numbers
						}
					}
				}


				while (std::getline(std::cin, s))
				istringstream iss(line);
				while(not eol)

				string first_on_line;
				string second_on_line;
				string third_on_line;
				if (iss >> first_on_line >> second_on_line >> third_on_line)
					...
			}
			// getline
			// first1 = first number read
			// first2 = second number read
			cout << "The first number in " + filename + " is " + first1 << endl;
			cout << "The second number in " + filename + " is " + first2 << endl;
			// interate through, saving each number in last1
			// switching last2 to last1, then saving the next in last1
			// when you reach eof, output last2 and last1
			cout << "The second-to-last number in " + filename + " is " + last2 << endl;
			cout << "The last number in " + filename + " is " + last1 << endl;

		}
		if (inputFile.fail())
		{
			cout << "Error reading input file" << strerror(errno) << endl;
		}
	}

	while (inputFile.getline(finalLine, 255))
	{
		cout << finalLine << endl;
	}
	if (inputFile.fail() && (!inputFile.eof()))
	{
		cout << "Error while reading file test.txt" << ". errno = " << strerror(errno) << endl;
	}

while ((!inputFile.eof()) || (!inputFile.fail()))
{
	inputFile.getline(finalLine, 255);
	cout << finalLine << endl;
}
if (inputFile.fail())
{
	cout << "Error reading input file" << strerror(errno) << endl;
}
	}

	while (inputFile.getline(finalLine, 255))
	{
		cout << finalLine << endl;
	}
	if (inputFile.fail() && (!inputFile.eof()))
	{
		cout << "Error while reading file test.txt" << ". errno = " << strerror(errno) << endl;
	}

	*/

