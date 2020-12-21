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
		int result = s.top();

		assert(result == 11);
	}

	{
		stack<String> s;
		s.push("Hello");
		s.push("World");
		String result = s.top();

		assert(result == "World");

	}

	std::cout << "Done Testing Top Of Stack" << std::endl;

}