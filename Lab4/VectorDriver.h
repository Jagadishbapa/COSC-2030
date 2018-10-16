/* File: VectorDriver.cpp
 * Athr: Dimitri Zarzhitsky
 * Date: October 16, 2002
 *
 * Desc: provides the basic framework and examples for an introduction to
 *       the STL::vector, iterators, and the algorithms facilities.
 *
 * Edited by: Rafe Cooley
 * Date: October 1, 2017 (the future)
 *
 * @name Tamara Linse
 * @date 10-15-2018
 * @file VectorDriver.h
 *
 * Program VectorDriver uses vectors and iterators to implement the following
 * methods: 
 *    fill_vector, which has pre-allocated space with consecutive numbers;
 *    print, which prints our vector in a fancy way;
 *    compute_sum, which uses iterator to sum the elements of a vector;
 *    add_numbers, which uses push_back to add numbers to the end of a vector; 
 *    print_even, which prints the elements of a vector with even indices;
 *    is_present, which uses an iterate to see if a value is present in a vector; and
 *    my_sort, which uses the STL function to sort a vector.
 */
typedef unsigned long ulong;

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::sort;

// fill vector that has pre-allocated space with consecutive numbers

void fill_vector(vector<short> &data) {
  for (ulong i=0; i<data.size(); i++) {
    data.at(i) = i;
  }
}

// print our vector in a fancy way

void print(const vector<short> &data) {
  if (data.empty()) {
    cout << "<empty>";
  } else {
    cout << "<" << data.at(0);
    for (ulong i=1; i<data.size(); i++) {
      cout << ", " << data.at(i);
    }
    cout << ">";
  }
}

// use iterator to sum the elements of a vector

short compute_sum(const vector<short> &data) {
  std::vector<short>::const_iterator iter = data.begin();

  short sum = 0;
  while (iter != data.end()) {
    sum += *iter;
    iter++;
  }

  return sum;
}

// --------------------------------- TODO ------------------------------------

// TODO: implement add_numbers
// add_numbers uses push_back to add numbers to the end of a vector

void add_numbers(vector<short> &data) {
	// for (vector<short>::iterator it = data.begin(); it != data.end(); ++it)
	for (int i = 0; i < 10; i++) {
		data.push_back(rand() % 100 + 1);
	}
}

// TODO: implement print_even
// print_even prints the elements of a vector with even indices

void print_even(const vector<short> &data) {
	if (data.empty()) {
		cout << "<empty>";
	}
	else {
		cout << "<" << data.at(0);
		for (ulong i = 0; i<data.size(); i += 2) {
			cout << ", " << data.at(i);
		}
		cout << ">";
	}
}

// TODO: implement is_present
// is_present uses an iterate to see if a value is present in a vector

bool is_present(const vector<short> &data, short value)
{
	bool present = false;
	vector<short>::const_iterator iter = data.begin();
	while (iter != data.end()) {
		if (*iter == value) {
			present = true;
		}
		iter++;
	}
	return present;
}

// TODO: implement std::sort function
// my_sort uses the STL function to sort a vector

void my_sort(vector<short> &data) {
	sort(data.begin(), data.end());
}

// ------------------------------------------------------------------------------
