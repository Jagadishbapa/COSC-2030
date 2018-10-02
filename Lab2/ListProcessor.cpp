// COSC 2030 Lab 2
// Tamara Linse

// ListProcessor.cpp

// tom bailey   1540  30 sep 2011

// tom bailey   1030  27 jan 2012
// Exercise the List class with verbose Node constructor
//   and destructor.

#include "LinkedList.h"


int main()
{
	List cows;
	cout << "cows list  :  " << cows << endl << endl;

	cows.insertAsFirst(1.23);
	cows.insertAsFirst(2.34);
	cout << "cows list  :  " << cows << endl << endl;

	cows.removeFirst();
	cout << "cows list  :  " << cows << endl << endl;

	List horses(cows);
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl << endl;

	horses.removeFirst();
	horses.insertAsFirst(5.67);
	cows.insertAsFirst(6.78);
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl << endl;

	List pigs;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;

	pigs = cows;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;

	pigs = horses;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;

	// --------------------- ADDED ---------------------

	// Testing size, sum, and insertAsLast

	int si = 0;
	double su = 0;

	List nums;

	cout << "nums list  :  " << nums << endl << endl;

	nums.insertAsLast(7.89);
	cout << "nums list  :  " << nums << endl;
	si = nums.sizeOfList();
	cout << "size of list  :  " << si << endl;
	su = nums.sum();
	cout << "sum of list  :  " << su << endl << endl;

	si = nums.sizeOfList();
	cout << "nums list  :  " << nums << endl;
	cout << "size of list  :  " << si << endl;
	su = nums.sum();
	cout << "sum of list  :  " << su << endl << endl;

	nums.insertAsFirst(1.23);
	cout << "nums list  :  " << nums << endl;
	si = nums.sizeOfList();
	cout << "size of list  :  " << si << endl;
	su = nums.sum();
	cout << "sum of list  :  " << su << endl << endl;

	nums.insertAsFirst(4.56);
	cout << "nums list  :  " << nums << endl;
	si = nums.sizeOfList();
	cout << "size of list  :  " << si << endl;
	su = nums.sum();
	cout << "sum of list  :  " << su << endl << endl;

	nums.insertAsFirst(7.89);
	cout << "nums list  :  " << nums << endl;
	si = nums.sizeOfList();
	cout << "size of list  :  " << si << endl;
	su = nums.sum();
	cout << "sum of list  :  " << su << endl << endl;

	nums.insertAsFirst(3.45);
	cout << "nums list  :  " << nums << endl;
	si = nums.sizeOfList();
	cout << "size of list  :  " << si << endl;
	su = nums.sum();
	cout << "sum of list  :  " << su << endl << endl;

	nums.insertAsFirst(9.10);
	cout << "nums list  :  " << nums << endl;
	si = nums.sizeOfList();
	cout << "size of list  :  " << si << endl;
	su = nums.sum();
	cout << "sum of list  :  " << su << endl << endl;

	nums.removeFirst();
	cout << "nums list  :  " << nums << endl;
	si = nums.sizeOfList();
	cout << "size of list  :  " << si << endl;
	su = nums.sum();
	cout << "sum of list  :  " << su << endl << endl;

	nums.removeFirst();
	cout << "nums list  :  " << nums << endl;
	si = nums.sizeOfList();
	cout << "size of list  :  " << si << endl;
	su = nums.sum();
	cout << "sum of list  :  " << su << endl << endl;

	nums.insertAsLast(7.89);
	cout << "nums list  :  " << nums << endl;
	si = nums.sizeOfList();
	cout << "size of list  :  " << si << endl;
	su = nums.sum();
	cout << "sum of list  :  " << su << endl << endl;

	// -------------------------------------------------

	cout << "End of code" << endl;

	system("pause");
	return 0;
}

