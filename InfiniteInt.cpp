/////////////////////////////// FILE HEADER ///////////////////////////////////
//
// Title: Infinite Integer
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
// This file contains and defines all the functions stated in InfiniteInt.h
// Contains the following methods:
// - 4 constructors for InfiniteInt()
// - 1 destructor for InfiniteInt()
// - 17 overloaded operators for InfiniteInt()
//
///////////////////////////////////////////////////////////////////////////////

#include "InfiniteInt.h"
#include <iostream>

vector<unsigned int>* InfiniteInt::getDigits() {
	return digits;
}

InfiniteInt::InfiniteInt() {
	vector<unsigned int> * number = new vector<unsigned int>;
	number->push_back(0);

	this->digits = number;
}

InfiniteInt::InfiniteInt(unsigned long long val) {
	vector<unsigned int>* number = new vector<unsigned int>;

	// If value is zero case
	if (val == 0) {
		number->insert(number->begin(), 0);
		this->digits = number;
		return;
	}

	// While val is more than 0, takes modulus of 10 and divides val by 10
	while (val > 0) {
		int digit = val % radix;
		val /= radix;
		number->insert(number->begin(), digit);
	}

	this->digits = number;
}

InfiniteInt::InfiniteInt(vector<unsigned int>* new_digits) {
	this->digits = new_digits;
}

InfiniteInt::InfiniteInt(const InfiniteInt &obj) {
	digits = new vector<unsigned int>;

	// Adds every digit of obj to the new digits vector
	for (int i = 0; i < obj.digits->size(); i++) {
		digits->push_back(obj.digits->at(i));
	}
}

InfiniteInt& InfiniteInt::operator=(const InfiniteInt &digits) {
	// If digits is a different number
	if (this != &digits) {
		this->digits->clear();

		for (int i = 0; i < digits.digits->size(); i++) {
			this->digits->push_back(digits.digits->at(i));
		}
	}

	return *this;
}

InfiniteInt::~InfiniteInt() {
	delete digits;
	digits = NULL;
}

ostream& operator<<(ostream &os, const InfiniteInt &digits) {
	for (int i = 0; i < digits.digits->size(); i++) {
		os << digits.digits->at(i);
	}

	return os;
}

istream& operator>>(istream &is, const InfiniteInt &digits) {
	string number;
	is >> number;

	for (int i = 0; i < number.size(); i++) {
		if (!isdigit(number.at(i))) {
			cout << "Invalid entry" << endl;
			return is;
		}
	}

	int val = stoi(number);

	digits.digits->clear();

	if (val == 0) {
		digits.digits->insert(digits.digits->begin(), 0);
		return is;
	}

	while (val > 0) {
		int digit = val % digits.radix;
		val /= digits.radix;
		digits.digits->insert(digits.digits->begin(), digit);
	}

	return is;
}

bool operator<(const InfiniteInt &first, const InfiniteInt &second) {
	string int1 = "";
	string int2 = "";

	// Converts both InfiniteInt's to strings
	for (int i = 0; i < first.digits->size(); i++) {
		int1 = int1 + std::to_string(first.digits->at(i));
	}

	for (int i = 0; i < second.digits->size(); i++) {
		int2 = int2 + std::to_string(second.digits->at(i));
	}

	int val1 = stoi(int1);
	int val2 = stoi(int2);
	
	if (val1 < val2) {
		return true;
	}

	return false;
}

bool operator>(const InfiniteInt &first, const InfiniteInt &second) {
	string int1 = "";
	string int2 = "";

	// Converts both InfiniteInt's to strings
	for (int i = 0; i < first.digits->size(); i++) {
		int1 = int1 + std::to_string(first.digits->at(i));
	}

	for (int i = 0; i < second.digits->size(); i++) {
		int2 = int2 + std::to_string(second.digits->at(i));
	}

	int val1 = stoi(int1);
	int val2 = stoi(int2);
	
	if (val1 > val2) {
		return true;
	}

	return false;
}

bool operator<=(const InfiniteInt &first, const InfiniteInt &second) {
	string int1 = "";
	string int2 = "";

	for (int i = 0; i < first.digits->size(); i++) {
		int1 = int1 + std::to_string(first.digits->at(i));
	}

	for (int i = 0; i < second.digits->size(); i++) {
		int2 = int2 + std::to_string(second.digits->at(i));
	}

	int val1 = stoi(int1);
	int val2 = stoi(int2);
	
	if (val1 <= val2) {
		return true;
	}

	return false;
}

bool operator>=(const InfiniteInt &first, const InfiniteInt &second) {
	string int1 = "";
	string int2 = "";

	for (int i = 0; i < first.digits->size(); i++) {
		int1 = int1 + std::to_string(first.digits->at(i));
	}

	for (int i = 0; i < second.digits->size(); i++) {
		int2 = int2 + std::to_string(second.digits->at(i));
	}

	int val1 = stoi(int1);
	int val2 = stoi(int2);
	
	if (val1 >= val2) {
		return true;
	}

	return false;
}

bool operator==(const InfiniteInt &first, const InfiniteInt &second) {
	string int1 = "";
	string int2 = "";

	for (int i = 0; i < first.digits->size(); i++) {
		int1 = int1 + std::to_string(first.digits->at(i));
	}

	for (int i = 0; i < second.digits->size(); i++) {
		int2 = int2 + std::to_string(second.digits->at(i));
	}

	int val1 = stoi(int1);
	int val2 = stoi(int2);
	
	if (val1 == val2) {
		return true;
	}

	return false;
}

bool operator!=(const InfiniteInt &first, const InfiniteInt &second) {
	string int1 = "";
	string int2 = "";

	for (int i = 0; i < first.digits->size(); i++) {
		int1 = int1 + std::to_string(first.digits->at(i));
	}

	for (int i = 0; i < second.digits->size(); i++) {
		int2 = int2 + std::to_string(second.digits->at(i));
	}

	int val1 = stoi(int1);
	int val2 = stoi(int2);
	
	if (val1 != val2) {
		return true;
	}

	return false;
}

InfiniteInt operator+(const InfiniteInt &first, const InfiniteInt &second) {
	long long num1 = 0;
	long long num2 = 0;

	for (int i = 0; i < first.digits->size(); i++) {
		num1 = num1 * 10;
		num1 += first.digits->at(i);
	}

	for (int i = 0; i < second.digits->size(); i++) {
		num2 = num2 * 10;
		num2 += second.digits->at(i);
	}

	long long finalVal = num1 + num2;

	return InfiniteInt(finalVal);
}

InfiniteInt operator-(const InfiniteInt &first, const InfiniteInt &second) {
	long long num1 = 0;
	long long num2 = 0;

	for (int i = 0; i < first.digits->size(); i++) {
		num1 = num1 * 10;
		num1 += first.digits->at(i);
	}

	for (int i = 0; i < second.digits->size(); i++) {
		num2 = num2 * 10;
		num2 += second.digits->at(i);
	}

	long long finalVal = num1 - num2;

	// If number is negative, return a default InfiniteInt with value 0
	if (finalVal < 0) {
		return InfiniteInt();
	}

	return InfiniteInt(finalVal);
}

InfiniteInt& InfiniteInt::operator+=(const InfiniteInt &second) {
	long long num1 = 0;
	long long num2 = 0;

	for (int i = 0; i < this->digits->size(); i++) {
		num1 = num1 * 10;
		num1 += this->digits->at(i);
	}

	for (int i = 0; i < second.digits->size(); i++) {
		num2 = num2 * 10;
		num2 += second.digits->at(i);
	}

	long long finalVal = num1 + num2;

	*this = finalVal;

	return *this;
}

InfiniteInt& InfiniteInt::operator-=(const InfiniteInt &second) {
	long long num1 = 0;
	long long num2 = 0;

	for (int i = 0; i < this->digits->size(); i++) {
		num1 = num1 * 10;
		num1 += this->digits->at(i);
	}

	for (int i = 0; i < second.digits->size(); i++) {
		num2 = num2 * 10;
		num2 += second.digits->at(i);
	}
	
	long long finalVal = num1 - num2;

	if (finalVal < 0) {
		*this = 0;

		return *this;
	}

	*this = finalVal;

	return *this;
}

InfiniteInt& InfiniteInt::operator++() {
	int size = this->digits->size();

	// Adds 1 to the last index of digits
	this->digits->at(size - 1) += 1;
	int carry = this->digits->at(size - 1) / this->radix;
	this->digits->at(size - 1) = this->digits->at(size - 1) % this->radix;

	// Checks if a number is equal to "10", sets carry to true if so,
	// adds one to the index before the current one.
	for (int i = size - 2; i >= 0; i--) {
		if (carry == 1) {
			this->digits->at(i) += 1;
			carry = this->digits->at(i) / this->radix;
			this->digits->at(i) = this->digits->at(i) % this->radix;
		}
	}

	// If the carry is still there (999 to 1000), adds the 1 to the beginning
	if (carry == 1) {
		this->digits->insert(this->digits->begin(), 1);
	}

	return *this;
}

InfiniteInt& InfiniteInt::operator--() {
	long long num1 = 0;

	for (int i = 0; i < this->digits->size(); i++) {
		num1 = num1 * 10;
		num1 += this->digits->at(i);
	}

	long long finalVal = num1 - 1;
	vector<unsigned int> * newThis = new vector<unsigned int>;

	// If finalVal is negative or 0, return a default InfiniteInt
	if (finalVal <= 0) {
		newThis->insert(newThis->begin(), 0);
		this->digits = newThis;

		return *this;
	}

	while (finalVal > 0) {
		int digit = finalVal % this->radix;
		finalVal /= this->radix;
		newThis->insert(newThis->begin(), digit);
	}

	this->digits = newThis;

	return *this;
}

InfiniteInt InfiniteInt::operator++(int) {
	InfiniteInt toRet(*this);

	int size = this->digits->size();

	this->digits->at(size - 1) += 1;
	int carry = this->digits->at(size - 1) / this->radix;
	this->digits->at(size - 1) = this->digits->at(size - 1) % this->radix;

	for (int i = size - 2; i >= 0; i--) {
		if (carry == 1) {
			this->digits->at(i) += 1;
			carry = this->digits->at(i) / this->radix;
			this->digits->at(i) = this->digits->at(i) % this->radix;
		}
	}

	if (carry == 1) {
		this->digits->insert(this->digits->begin(), 1);
	}

	return toRet;
}

InfiniteInt InfiniteInt::operator--(int) {
	InfiniteInt toRet(*this);

	long long num1 = 0;

	for (int i = 0; i < this->digits->size(); i++) {
		num1 = num1 * 10;
		num1 += this->digits->at(i);
	}

	long long finalVal = num1 - 1;
	vector<unsigned int> * newThis = new vector<unsigned int>;

	if (finalVal <= 0) {
		newThis->insert(newThis->begin(), 0);
		this->digits = newThis;

		return toRet;
	}

	while (finalVal > 0) {
		int digit = finalVal % this->radix;
		finalVal /= this->radix;
		newThis->insert(newThis->begin(), digit);
	}

	this->digits = newThis;

	return toRet;
}
