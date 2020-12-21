#include <iostream>
#include <fstream>
#include "stack.hpp"
#include "string.hpp"
#include "utilities.hpp"

int main(int argc, char const* argv[])
{
	if (argc == 0 || argc > 3)
		std::cerr << "Invalid Input" << std::endl;

	// Opens Postfix File
	std::ifstream postfix_file(argv[1]);

	// Opens Output File
	std::ofstream out_file(argv[2]);


	if (!postfix_file)
		std::cerr << "Postfix file could not be opened" << std::endl;

	if (!out_file && argc == 3)
		std::cerr << "Output file could not be opened" << std::endl;

	if (argc == 3)
		while (!postfix_file.eof()) {

			postfix_to_assembly(postfix_file, out_file);

			if (postfix_file.peek() == postfix_file.eof())
				break;
		}
	else
		while (!postfix_file.eof()) {

			postfix_to_assembly(postfix_file, std::cout);

			if (postfix_file.peek() == postfix_file.eof())
				break;
		}


	std::cout << "   Done With File." << std::endl;
	postfix_file.close();
	out_file.close();

	return 1;
}