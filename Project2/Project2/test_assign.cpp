#include <iostream>
#include <cassert>
#include "string.hpp"
#include "stack.hpp"

int main()
{

	{
		stack<int> s;

		s.push(1);
		s.push(2);
		s.push(4);

		stack<int> c = s;

		int result = c.pop();
		assert(result == 4);

		result = c.pop();
		assert(result == 2);

		result = c.pop();
		assert(result == 1);
	}

	{

		stack<String> s;

		s.push("Hello");
		s.push("World");

		stack<String> c = s;

		String result = c.pop();
		assert(result == "World");

		result = c.pop();
		assert(result == "Hello");

	}

	std::cout << "Done Testing Equal Operator" << std::endl;

}