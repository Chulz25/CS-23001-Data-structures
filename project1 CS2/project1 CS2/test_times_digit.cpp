// bigint Test Program
//
// Tests:  times_10, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.h"

//===========================================================================
int main() {
	{
		//------------------------------------------------------
		// Setup fixture
		bigint bi(3);

		// Test 
		bi = bi.times_digit(1);

		// Verify
		assert(bi == 3);

		//Print
		std::cout << bi << " == 3" << std::endl;
	}

	{
		//------------------------------------------------------
		// Setup fixture
		bigint bi(0);

		// Test 
		bi = bi.times_digit(3);

		// Verify
		assert(bi == 0);

		//Print
		std::cout << bi << " == 0" << std::endl;
	}

	{
		//------------------------------------------------------
		// Setup fixture
		bigint bi(1);

		// Test 
		bi = bi.times_digit(9);

		// Verify
		assert(bi == 9);

		//Print
		std::cout << bi << " == 9" << std::endl;
	}

	{
		//------------------------------------------------------
		// Setup fixture
		bigint bi(24);

		// Test 
		bi = bi.times_digit(3);

		// Verify
		assert(bi == 72);

		//Print
		std::cout << bi << " == 72" << std::endl;
	}

	{
		//------------------------------------------------------
		// Setup fixture
		bigint bi(9999);

		// Test 
		bi = bi.times_digit(2);

		// Verify
		assert(bi == 19998);

		//Print
		std::cout << bi << " == 19998" << std::endl;
	}

	{
		//------------------------------------------------------
		// Setup fixture
		bigint bi(78654);

		// Test 
		bi = bi.times_digit(5);

		// Verify
		assert(bi == 393270);

		//Print
		std::cout << bi << " == 393270" << std::endl;
	}

	{
		//------------------------------------------------------
		// Setup fixture
		bigint bi("8765467890");

		// Test 
		bi = bi.times_digit(2);

		// Verify
		assert(bi == "17530935780");

		//Print
		std::cout << bi << " == 17530935780" << std::endl;
	}


	std::cout << "Done testing bigint * digit" << std::endl;

}