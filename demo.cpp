/////////////////////////////// FILE HEADER ///////////////////////////////////
//
// Title: Infinite Integer Demo
// Files: InfiniteInt.h, InfiniteInt.cpp, demo.cpp, Makefile, README.md
// Course: CS 368, Spring 2020
//
// Author: Matt Thompson
// Student ID: 9081263262
// Email: mathompson23@wisc.edu
// Lecturer's Name: Marc Renault
//
// Online Sources:
// - https://stackoverflow.com/questions/4427738/allocate-memory-for-a-vector
//
// - http://www.enseignement.polytechnique.fr/informatique/INF478/docs/Cpp/
//   en/cpp/language/as_operator.html
// 
// - https://stackoverflow.com/questions/4261589/how-do-i-split-an-int-into
//   -its-digits
//
// - https://stackoverflow.com/questions/9438209/for-every-character-in-string
//
// - https://stackoverflow.com/questions/28607912/sum-values-of-2-
//   vectors/28607985
//
// - https://www.geeksforgeeks.org/adding-one-to-number-represented-
//   as-array-of-digits/
//
// - https://stackoverflow.com/questions/12239015/how-to-append-an-integer
//   -with-an-integer-in-c/12239029
//
//////////////////////////// FILE DESCRIPTION /////////////////////////////////
// 
// This file demo's all the functions in InfiniteInt, calling all the functions 
// in InfiniteInt.cpp.
//
///////////////////////////////////////////////////////////////////////////////

#include "InfiniteInt.h"
#include <iostream>

using namespace std;

int main() {
    // Testing long param constructor and no-arg constructor
    cout << "Constructing n1 and n2..." << endl;
    InfiniteInt n1(412);
    InfiniteInt n2;
    cout << "n1 should be 412: " << n1 << endl;
    cout << "n2 should be 0: " << n2 << endl;
    cout << endl;

    //Testing copy operator=
    cout << "Changing value of n1 and n2..." << endl;
    n1 = 2;
    n2 = 3;
    cout << "n1 should be 2: " << n1 << endl;
    cout << "n2 should be 3: " << n2 << endl;
    cout << endl;

    // Testing copy constructor
    cout << "Constructing n3..." << endl;
    InfiniteInt n3(n2);
    cout << "n3 should be 3: " << n3 << endl;
    cout << endl;

    // Testing vector parameter constructor
    cout << "Constructing n4..." << endl;
    vector<unsigned int> * numbers = new vector<unsigned int>;
    numbers->push_back(5);
    numbers->push_back(2);
    InfiniteInt n4(numbers);
    cout << "n4 should be 52: " << n4 << endl;
    cout << endl;

    // Testing output operator
    cout << "Output operator:" << endl;
    operator<<(cout, n3) << endl;
    cout << "n3 should be 3: " << n3 << endl;
    cout << endl;

    // Testing input operator
    cout << "Input operator:" << endl;
    operator>>(cin, n3);
    cout << "n3 should be 10: " << n3 << endl;
    cout << endl;

    // Testing operator< and operator>
    cout << "operator<: " << operator<(n2, n3) << endl;
    cout << "operator>: " << operator>(n2, n3) << endl;
    cout << endl;

    // Testing operator<= and operator>=
    cout << "operator<=: " << operator<=(n2, n3) << endl;
    cout << "operator>=: " << operator>=(n2, n3) << endl;
    cout << endl;

    // Testing operator== and operator!=
    cout << "operator==: " << operator==(n2, n3) << endl;
    cout << "operator!=: " << operator!=(n2, n3) << endl;
    cout << endl;

    // Testing operator+ and operator-
    cout << "operator+: " << operator+(n2, n3) << endl;
    cout << "operator-: " << operator-(n2, n3) << endl;
    cout << endl;

    // Testing operator+= and operator-=
    cout << "operator+=: (" << n2 << " += " << n3 << ") = " << (n2 += n3) << endl;
    cout << "operator-=: (" << n2 << " -= " << n3 << ") = " << (n2 -= n3) << endl;
    cout << endl;

    // Testing ++operator and --operator
    cout << "++operator: " << ++n2 << endl;
    cout << "--operator: " << --n2 << endl;
    cout << endl;

    // Testing operator++ and operator--
    cout << "operator++: " << n3++ << ". After increment: " << n3 << endl;
    cout << "operator--: " << n3-- << ". After decrement: " << n3 << endl;

    return 0;
}