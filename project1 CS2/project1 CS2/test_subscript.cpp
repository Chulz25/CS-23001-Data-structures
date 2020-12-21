// bigint Test Program
//
// Tests:  subscript, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.h"

//===========================================================================
int main() {

	{
		// Setup
		bigint bi(4);

		// Test 
		int digit = bi[0];

		// Verify
		assert(bi == 4);
		assert(digit == 4);

		std::cout << "bi == " << bi << std::endl;
		std::cout << "bi[0] == " << digit << std::endl;
	}

	{
		// Setup
		bigint bi(23);

		// Test 
		int digit = bi[1];

		// Verify
		assert(bi == 23);
		assert(digit == 3);

		std::cout << "bi == " << bi << std::endl;
		std::cout << "bi[1] == " << digit << std::endl;
	}

	{
		// Setup
		bigint bi(6543567);

		// Test 
		int digit = bi[4];

		// Verify
		assert(bi == 6543567);
		assert(digit == 5);

		std::cout << "bi == " << bi << std::endl;
		std::cout << "bi[4] == " << digit << std::endl;
	}

	{
		// Setup
		bigint bi("754324567890876543567897654356789076543567890");

		// Test 
		int digit = bi[15];

		// Verify
		assert(bi == "754324567890876543567897654356789076543567890");
		assert(digit == 5);

		std::cout << "bi == " << bi << std::endl;
		std::cout << "bi[15] == " << digit << std::endl;
	}

	{
		// Setup
		bigint bi(546789765);

		// Test 
		int digit = bi[2];

		// Verify
		assert(bi == 546789765);
		assert(digit != 5);


		std::cout << "bi == " << bi << std::endl;
		std::cout << "bi[2] == " << bi[2] << std::endl;
		std::cout << bi[2] << " != " << "5" << std::endl;
	}

	{
		// Setup
		bigint bi;

		// Test 
		int digit = bi[0];

		// Verify
		assert(bi == 0);
		assert(digit == 0);

		std::cout << "bi == " << bi << std::endl;
		std::cout << "bi[0] == " << digit << std::endl;
	}

	{
		// Setup
		bigint bi(98976543);

		// Test 
		int digit = bi[0];

		// Verify
		assert(bi == 98976543);
		assert(digit == 9);

		std::cout << "bi == " << bi << std::endl;
		std::cout << "bi[0] == " << digit << std::endl;
	}

	std::cout << "Done testing subscript." << std::endl;
}