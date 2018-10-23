// COSC 2030
// Lab 5
// @author Tamara Linse
// @date 10.22.2018
// @file Lab5MyStack.cpp

#include <iostream>
#include <cmath>
#include <stack>
#include <string>
#include <vector>
#include <list>
#include "Lab5MyStack.h"

using namespace std;

void stringReversal1(string input)
{
	stack <char> s;
	string output[30];
	cout << "Your input string is " << input << endl;
	cout << "Your initial stack of char is ";
	for (int i = 0; i < input.length(); i++)
	{
		cout << input[i];
		s.push(input[i]);
	}
	cout << endl;
	cout << "Your reversed output string is ";
	int j = 0;
	while (!s.empty())
	{
		output[j] = s.top();
		cout << output[j];
		s.pop();
	}
	cout << endl;
	cout << endl;
}

void stringReversal2(string input)
{
	vector <char> v;
	string output[30];
	cout << "Your input string is " << input << endl;
	cout << "Your initial vector of char is ";
	for (int i = 0; i < input.length(); i++)
	{
		cout << input[i];
		v.push_back(input[i]);
	}
	cout << endl;
	cout << "Your reversed output string is ";
	int j = 0;
	while (!v.empty())
	{
		output[j] = v.back();
		cout << output[j];
		v.pop_back();
	}
	cout << endl;
	cout << endl;
}

void stringReversal3(string input)
{
	list <char> l;
	string output[30];
	cout << "Your input string is " << input << endl;
	cout << "Your initial list of char is ";
	for (int i = 0; i < input.length(); i++)
	{
		cout << input[i];
		l.push_back(input[i]);
	}
	cout << endl;
	cout << "Your reversed output string is ";
	int j = 0;
	while (!l.empty())
	{
		output[j] = l.back();
		cout << output[j];
		l.pop_back();
	}
	cout << endl;
	cout << endl;

}

bool MyStack::isEmpty() const
{
	if (v.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void MyStack::push(char& c)
{
	v.push_back(c);
}

char MyStack::pull()
{
	char a = v.back();
	v.pop_back();
	return a;
}

void stringReversal4(string input)
{
	MyStack v;
	string output[30];
	cout << "Your input string is " << input << endl;
	cout << "Your initial MyString of char is ";
	for (int i = 0; i < input.length(); i++)
	{
		cout << input[i];
		v.push(input[i]);
	}
	cout << endl;
	cout << "Your reversed output string is ";
	int j = 0;
	while (!v.isEmpty())
	{
		output[j] = v.pull();
		cout << output[j];
	}
	cout << endl;
	cout << endl;

}
