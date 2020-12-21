#include <iostream>
#include <cassert>
#include "string.hpp"
#include "stack.hpp"

int main()
{

	{

		stack<int> s;

		s.push(1);
		s.push(23);
		s.push(101);

		stack<int> c(s);

		int result = c.pop();
		assert(result == 101);

		result = c.pop();
		assert(result == 23);

		result = c.pop();
		assert(result == 1);
	}

	{
		stack<String> s;

		s.push("Hello");
		s.push("World");

		stack<String> c(s);

		String result = c.pop();
		assert(result == "World");

		result = c.pop();
		assert(result == "Hello");

	}

	std::cout << "Done Testing Copy Constructor" << std::endl;

}