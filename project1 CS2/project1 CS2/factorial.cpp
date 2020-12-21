/**
 * Joel Robert Lee
 * Bigint Factorial
 * CS 23001
 */

 // Can compute the factorial of a bigint

#include <iostream>
#include "bigint.h"

bigint factorial(bigint num) {

	bigint result(1);

	int convertBigint;

	// Converts the bigint to an integer value based on how many digits it hold
	// the max it can hold is about 500


	if (num.getSize() == 1)
		convertBigint = num.container[0];
	else if (num.getSize() == 2)
		convertBigint = num.container[0] + (num.container[1] * 10);
	else if (num.getSize() == 3) {
		convertBigint = num.container[0] + (num.container[1] * 10) + (num.container[2] * 100);
		if (convertBigint > 252) {
			std::cout << "Result to large for bigint to contain (Maximum Value = 252)";
			return 0;
		}
	}
	else {

		std::cout << "Result to large for bigint to contain (Bigint value must be 3 digits or less)";
		return 0;

	}

	// Computes Factorial Calculations
	for (int i = convertBigint; i > 0; --i)
		result = result * i;


	int trailingZero = 0;
	// Computes the number of trailing 0's on the result of the factorial computation
	for (int i = 0; i < result.getSize(); ++i)
		if (result.container[i] == 0) {
			++trailingZero;
			if (result.container[i + 1] != 0)
				break;

		}

	std::cout << "There are " << trailingZero << " Trailing Zeros on " << convertBigint << " Factorial" << std::endl << std::endl;

	return result;

}



int main() {

	bigint a(100);

	std::cout << factorial(a) << std::endl << std::endl;

	std::cout << "The factorial of a bigint is calculated by converting the bigint into its integer equivalence" << std::endl;
	std::cout << "This is possible because the factorial of a number larger that 3 digits cannot be held by a bigint" << std::endl;
	std::cout << "Once the conversion is made, the function simply loops from the integer to 1 while multiplying" << std::endl;
	std::cout << "The next lowest number into the result like one would when calculating a factorial by hand" << std::endl << std::endl;

	std::cout << "One could determine the number of trailing zeros on a factorial mathematically by" << std::endl;
	std::cout << "Dividing the number by 5 and keep track of the result" << std::endl;
	std::cout << "Increase the power by 5 each time (number/5^1, number/5^2, number/5^3) until a number less than 0 is reached" << std::endl;
	std::cout << "Sum all of the results of the division and you have your answer" << std::endl;

}