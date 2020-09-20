/////////////////////////////// FILE HEADER ///////////////////////////////////
//
// Title: Infinite Integer Header
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
// This program represents an InfiniteInt, a number which is represented as a
// vector of unsigned integers. The program has 4 constructors and 1 destructor
// which create the InfiniteInt object, and 17 operators that manipulate the
// InfiniteInt's in a variety of arithmetic ways.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef InfiniteInt_H
#define InfiniteInt_H

#include <iostream>
#include <vector>
#include <string>

/**
 * The InfiniteInt class holds two private fields (pertinent to the InfiniteInt),
 * and (all public methods) the four constructors, the destructor, and the 17
 * operators.
 *
 * @author Matt Thompson
 */
class InfiniteInt {
private:
	vector<unsigned int>* digits; // Container that stores the digits of the InfiniteInt
	const unsigned int radix = 10; // Represents the base of the number

public:
	/*
	 * Getter function for the digits member variable
	 * 
	 * @return The digits vector variable
	 */
	vector<unsigned int>* getDigits();

	/**
 	 * Default constructor for InfiniteInt. Sets the InfiniteInt to a default 
 	 * value of 0.
 	 */
	InfiniteInt();

	/**
 	 * Parameterized constructor for InfiniteInt, setting it to the specified
 	 * long long val.
 	 *
 	 * @param val The value to be assigned to the newly constructed InfiniteInt
 	 */
	InfiniteInt(unsigned long long val);

	/**
 	 * Parameterized constructor for InfiniteInt, setting its value to the
 	 * digits pointed to by new_digits.
 	 *
 	 * @param new_digits The vector of unsigned ints to be assigned to the
 	 *  	             newly created InfiniteInt.
 	 */
	explicit InfiniteInt(vector<unsigned int>* new_digits);

	/**
 	 * Copy constructor for InfiniteInt, which allocates new memory for
 	 * InfiniteInt's "digits" field and copies all the digits from the
 	 * obj vector to the new digits vector.
 	 *
 	 * @param &obj Address of the InfiniteInt that will be used to create
 	 * 			   a copy.
 	 */
	InfiniteInt(const InfiniteInt &obj);

	/**
 	 * Copy-assignment operator which takes in an InfiniteInt and replaces
 	 * "this" InfiniteInt's digits with the new InfiniteInt's digits value.
 	 *
 	 * @param & Address of the InfiniteInt that will be used to create a
 	 * 		    copy.
 	 * @return A *this modified InfiniteInt
 	 */
	InfiniteInt& operator=(const InfiniteInt &);

	/**
 	 * Destructor method that frees the memory for unused InfiniteInt's.
 	 */
	~InfiniteInt();

	/**
 	 * Output stream operator that displays any InfiniteInt as it if were a
 	 * regular unsigned integer value.
 	 *
 	 * @param &os Reference to the output stream
 	 * @param &digits InfiniteInt to be displayed by the output operator
 	 * @return The output stream reference
 	 */
	friend ostream& operator<<(ostream &os, const InfiniteInt &digits);

	/**
 	 * Input stream operator that waits for the user to input a single
 	 * string of numbers, which will be parsed into a vector of digits.
 	 *
 	 * @param &is Reference to the input stream
 	 * @param &digits InfiniteInt where the input values will be allocated
 	 * @return The input stream reference.
 	 */
	friend istream& operator>>(istream &is, const InfiniteInt &digits);

	/**
 	 * Operator less than (<) that returns whether or not the value on
 	 * the left hand side InfiniteInt is less than the right hand InfiniteInt.
 	 *
 	 * @param &first The left hand side digit.
 	 * @param &second The right hand side digit.
 	 * @return true if the left side digit is less than the right hand digit,
 	 * 		   false otherwise.
 	 */
	friend bool operator<(const InfiniteInt &first, const InfiniteInt &second);

	/**
 	 * Operator more than (>) that returns whether or not the value on
 	 * the left hand side InfiniteInt is more than the right hand InfiniteInt.
 	 *
 	 * @param &first The left hand side digit.
 	 * @param &second The right hand side digit.
 	 * @return true if the left side digit is more than the right hand digit,
 	 * 		   false otherwise.
 	 */
	friend bool operator>(const InfiniteInt &first, const InfiniteInt &second);

	/**
 	 * Operator less or equal than (<=) that returns whether or not the value on
 	 * the left hand side InfiniteInt is less or equal to the right hand InfiniteInt.
 	 *
 	 * @param &first The left hand side digit.
 	 * @param &second The right hand side digit.
 	 * @return true if the left side digit is less or equal to the right hand 
 	 * digit, false otherwise.
 	 */
	friend bool operator<=(const InfiniteInt &first, const InfiniteInt &second);

	/**
 	 * Operator more or equal than (>=) that returns whether or not the value on
 	 * the left hand side InfiniteInt is more or equal to the right hand InfiniteInt.
 	 *
 	 * @param &first The left hand side digit.
 	 * @param &second The right hand side digit.
 	 * @return true if the left side digit is more or equal to the right hand 
 	 * digit, false otherwise.
 	 */
	friend bool operator>=(const InfiniteInt &first, const InfiniteInt &second);

	/**
 	 * Operator equals (==) that returns whether or not the value on
 	 * the left hand side InfiniteInt is equal to the right hand InfiniteInt.
 	 *
 	 * @param &first The left hand side digit.
 	 * @param &second The right hand side digit.
 	 * @return true if the left side digit is equal to the right hand digit, 
 	 * false otherwise.
 	 */
	friend bool operator==(const InfiniteInt &first, const InfiniteInt &second);

	/**
 	 * Operator not equals (!=) that returns whether or not the value on
 	 * the left hand side InfiniteInt is not equal to the right hand InfiniteInt.
 	 *
 	 * @param &first The left hand side digit.
 	 * @param &second The right hand side digit.
 	 * @return true if the left side digit is not equal to the right hand digit, 
 	 * false otherwise.
 	 */
	friend bool operator!=(const InfiniteInt &first, const InfiniteInt &second);

	/**
 	 * Operator sum (+) that returns the sum of two InfiniteInt's.
 	 *
 	 * @param &first The first InfiniteInt to be added.
 	 * @param &second The second InfiniteInt to be added.
 	 * @return A new InfiniteInt with the added total of both InfiniteInt's.
 	 */
	friend InfiniteInt operator+(const InfiniteInt &first, const InfiniteInt &second);

	/**
 	 * Operator sum (-) that returns the difference of two InfiniteInt's.
 	 *
 	 * @param &first The first InfiniteInt to be added.
 	 * @param &second The second InfiniteInt to be added.
 	 * @return A new InfiniteInt with the subtracted total of both InfiniteInt's.
 	 */
	friend InfiniteInt operator-(const InfiniteInt &first, const InfiniteInt &second);

	/**
 	 * Operator plus equals (+=) that adds the second InfiniteInt to the first
 	 * InfiniteInt and stores the value in the first InfiniteInt. (*this)
 	 *
 	 * @param &second The second InfiniteInt to be added onto the first InfiniteInt.
 	 * @return Modified left hand side InfiniteInt with the added total of 
 	 * 		   both InfiniteInt's.
 	 */
	InfiniteInt& operator+=(const InfiniteInt &second);

	/**
 	 * Operator minus equals (-=) that subtracts the second InfiniteInt to the first
 	 * InfiniteInt and stores the value in the first InfiniteInt. (*this)
 	 *
 	 * @param &second The second InfiniteInt to be subtracted to the first InfiniteInt.
 	 * @return Modified left hand side InfiniteInt with the subtracted total of 
 	 * 		   both InfiniteInt's.
 	 */
	InfiniteInt& operator-=(const InfiniteInt &second);

	/**
 	 * Pre-increment operator (++InfiniteInt) that adds one to the current InfiniteInt
 	 * and returns the changed InfiniteInt
 	 *
 	 * @return The changed, incremented InfiniteInt
 	 */
	InfiniteInt& operator++();

	/**
 	 * Pre-decrement operator (--InfiniteInt) that subtracts one to the current InfiniteInt
 	 * and returns the changed InfiniteInt
 	 *
 	 * @return The changed, decremented InfiniteInt
 	 */
	InfiniteInt& operator--();

	/**
 	 * Post-increment operator (InfiniteInt++) that adds one to the current InfiniteInt
 	 * and returns the original InfiniteInt
 	 *
 	 * @param int Parameter for program to differentiate that this is the post-increment 
 	 * 		      operator.
 	 * @return The original, unchanged InfiniteInt
 	 */
	InfiniteInt operator++(int);

	/**
 	 * Post-decrement operator (InfiniteInt--) that subtracts one to the current InfiniteInt
 	 * and returns the original InfiniteInt
 	 *
 	 * @param int Parameter for program to differentiate that this is the post-decrement 
 	 * 		      operator.
 	 * @return The original, unchanged InfiniteInt
 	 */
	InfiniteInt operator--(int);
};
#endif // InfiniteInt_H