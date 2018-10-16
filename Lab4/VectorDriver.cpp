#include "VectorDriver.h"

/*
* @name Tamara Linse
* @date 10 - 15 - 2018
* @file VectorDriver.cpp
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
*
* Below are unit tests for methods in header file.
*
*/

int main() {
  cout << "  ..:: B E G I N  S A M P L E  C O D E  ::.." << endl << endl;

  // Filled Vector

  vector<short> sample_vector(5);

  cout << "new vector: ";
  print(sample_vector);
  cout << endl << endl;

  fill_vector(sample_vector);

  cout << "filled vector: ";
  print(sample_vector);
  cout << endl;

  cout << "sum of vector's elements: " << compute_sum(sample_vector) << endl;
  cout << endl << endl;

  // --------------------------------- TODO ------------------------------------

  // Push_Back and Print_Even

  vector<short> sample_vector2(0);

  cout << "new vector: ";
  print(sample_vector2);
  cout << endl;

  add_numbers(sample_vector2);
  add_numbers(sample_vector2);


  cout << "filled vector: ";
  print(sample_vector2);
  cout << endl;

  cout << "print even of vector: ";
  print_even(sample_vector2);

  cout << endl << endl;

  // Is_Present

  vector<short> sample_vector3(5);

  cout << "new vector: ";
  print(sample_vector3);
  cout << endl;

  fill_vector(sample_vector3);

  cout << "filled vector: ";
  print(sample_vector3);
  cout << endl;

  short value = 3;
  cout << "Is " << value << " present? " << is_present(sample_vector3, value) << endl;
  cout << endl << endl;

  // Sort Using Vectors and Iterators

  vector<short> sample_vector4(5);

  cout << "new vector: ";
  print(sample_vector4);
  cout << endl;

  add_numbers(sample_vector4);

  cout << "filled vector: ";
  print(sample_vector4);
  cout << endl;

  my_sort(sample_vector4);

  cout << "sorted vector: ";
  print(sample_vector4);
  cout << endl << endl;

  // -----------------------------------------------------------------------------

  cout << endl << "   ..::  E N D   S A M P L E  C O D E  ::..\n" << endl;
  system("pause");
  return 0;
}
