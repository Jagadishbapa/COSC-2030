// COSC 2030
// Lab 5
// @author Tamara Linse
// @date 10.22.2018
// @file Lab5MyStack.h

#ifndef LAB5_H_
#define LAB5_H_

#include <iostream>
#include <cmath>
#include <stack>
#include <string>
#include <vector>
#include <list>

using namespace std;

void stringReversal1(string input);
void stringReversal2(string input);
void stringReversal3(string input);
void stringReversal4(string input);

class MyStack
{
	// vector <char> v;
	list <char> v;
public:
	bool isEmpty() const;
	void push(char& c);
	char pull();
};


#endif


