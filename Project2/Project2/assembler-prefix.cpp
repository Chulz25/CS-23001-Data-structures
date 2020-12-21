#include <iostream>
#include <fstream>
#include "stack.hpp"
#include "string.hpp"
#include "utilities.hpp"

int main(int argc, char const* argv[])
{
	if (argc == 0 || argc > 3)
		std::cerr << "Invalid Input" << std::endl;

	// Opens Prefix File
	std::ifstream prefix_file(argv[1]);

	// Opens Output File
	std::ofstream out_file(argv[2]);


	if (!prefix_file)
		std::cerr << "Prefix file could not be opened" << std::endl;

	if (!out_file && argc == 3)
		std::cerr << "Output file could not be opened" << std::endl;

	if (argc == 3)
		while (!prefix_file.eof()) {

			prefix_to_assembly(prefix_file, out_file);

			if (prefix_file.peek() == prefix_file.eof())
				break;
		}
	else
		while (!prefix_file.eof()) {

			prefix_to_assembly(prefix_file, std::cout);

			if (prefix_file.peek() == prefix_file.eof())
				break;
		}


	std::cout << "   Done With File." << std::endl;
	prefix_file.close();
	out_file.close();

	return 1;
