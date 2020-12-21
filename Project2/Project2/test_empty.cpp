#include <iostream>
#include <cassert>
#include "string.hpp"
#include "stack.hpp"

int main()
{

	{
		stack<int> s;

		s.push(65);
		s.push(20);
		s.push(11);

		assert(s.empty() == false);
	}

	{
		stack<int> s;

		assert(s.empty() == true);
	}


	std::cout << "Done Testing Empty" << std::endl;

}