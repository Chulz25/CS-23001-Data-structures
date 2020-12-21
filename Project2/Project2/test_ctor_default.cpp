#include <iostream>
#include <cassert>
#include "string.hpp"
#include "stack.hpp"

int main()
{

	{
		stack<int> s;

		assert(s.empty());
	}

	std::cout << "Done Testing Default ctor" << std::endl;

}