#pragma once
/**
 * Joel Lee
 * Bigint
 * cs23001
 */

 //the reason is for to create type bigint so that it can hold an integer larger
 //Than the base int Type can hold
 //header file for bigint.cpp



#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>

//The capacity of the bigint must be specified by a global constant CAPACITY, use: const int CAPACITY = 400;
const int Capacity = 400;

class bigint {

public:
	bigint();
	bigint(int n);
	bigint(const char[]);
	
	int getSize();
	
	void setSize(int);
	void debugPrint(std::ostream&) const;
	
	bool operator==(bigint);
	int operator[](int) const;
	
	bigint operator+(const bigint&) const;
	
	bigint times_digit(int) const;
	
	bigint times_10(int) const;
	
	bigint operator*(const bigint&) const;
	
	int container[Capacity];


private:
	int size;
};

	std::ostream& operator<<(std::ostream&, bigint);
	std::istream& operator>>(std::istream&, bigint&);


#endif