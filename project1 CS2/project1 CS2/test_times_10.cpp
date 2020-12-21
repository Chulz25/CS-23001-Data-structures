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
		bi = bi.times_10(0);

		// Verify
		assert(bi == 3);

		//Print
		std::cout << bi << " == 3" << std::endl;
	}

	{
		//------------------------------------------------------
		// Setup fixture
		bigint bi(2);

		// Test 
		bi = bi.times_10(1);

		// Verify
		assert(bi == 20);

		//Print
		std::cout << bi << " == 20" << std::endl;
	}

	{
		//------------------------------------------------------
		// Setup fixture
		bigint bi(54);

		// Test 
		bi = bi.times_10(2);

		// Verify
		assert(bi == 5400);

		//Print
		std::cout << bi << " == 5400" << std::endl;
	}

	{
		//------------------------------------------------------
		// Setup fixture
		bigint bi("3");

		// Test 
		bi = bi.times_10(4);

		// Verify
		assert(bi == 30000);

		//Print
		std::cout << bi << " == 30000" << std::endl;
	}

	{
		//------------------------------------------------------
		// Setup fixture
		bigint bi(654678);

		// Test 
		bi = bi.times_10(3);

		// Verify
		assert(bi == 654678000);

		//Print
		std::cout << bi << " == 654678000" << std::endl;
	}

	{
		//------------------------------------------------------
		// Setup fixture
		bigint bi("786546789876546789076546789");

		// Test 
		bi = bi.times_10(10);

		// Verify
		assert(bi == "7865467898765467890765467890000000000");

		//Print
		std::cout << bi << " == 7865467898765467890765467890000000000" << std::endl;
	}

	std::cout << "Done testing times_10" << std::endl;
}