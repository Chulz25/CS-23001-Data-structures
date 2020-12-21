#include <iostream>
#include <fstream>
#include "stack.hpp"
#include "string.hpp"
#include "utilities.hpp"

int main(int argc, char const* argv[])
{
	if (argc == 0 || argc > 3)
		std::cerr << "Invalid Input" << std::endl;

	// Opens Infix File
	std::ifstream infix_file(argv[1]);

	// Opens Output File
	std::ofstream out_file(argv[2]);


	if (!infix_file)
		std::cerr << "Infix file could not be opened" << std::endl;

	if (!out_file && argc == 3)
		std::cerr << "Output file could not be opened" << std::endl;

	if (argc == 3)
		infix_to_postfix(infix_file, out_file);
	else
		infix_to_postfix(infix_file, std::cout);


	infix_file.close();
	out_file.close();
}