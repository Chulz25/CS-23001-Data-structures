#include <iostream>
#include <cassert>
#include "string.hpp"
#include "stack.hpp"

int main()
{

	{
		// Single Integer test //////////////////
		stack<int> s;

		s.push(1);
		int result = s.pop();

		assert(result == 1);
		/////////////////////////////////////////


		// Single String test //////////////////
		stack<String> sString;

		sString.push("Hello");
		String sresult = sString.pop();

		assert(sresult == "Hello");
		/////////////////////////////////////////


		// Single Char test /////////////////////
		stack<char> schar;

		schar.push('a');
		char cresult = schar.pop();

		assert(cresult == 'a');
		/////////////////////////////////////////
	}

	{
		// Multiple int test /////////////////////
		stack<int> s;

		s.push(1);
		s.push(2);
		s.push(3);

		int result = s.pop();

		assert(result == 3);

		result = s.pop();

		assert(result == 2);

		result = s.pop();

		assert(result == 1);
		//////////////////////////////////////////


		// Multiple String test //////////////////
		stack<String> sstring;

		sstring.push("Hello");
		sstring.push("How");
		sstring.push("You?");

		String sresult = sstring.pop();

		assert(sresult == "You?");

		sresult = sstring.pop();

		assert(sresult == "How");

		sresult = sstring.pop();

		assert(sresult == "Hello");
		//////////////////////////////////////////


		// Multiple Char test //////////////////
		stack<char> cstring;

		cstring.push('a');
		cstring.push('b');
		cstring.push('c');

		char cresult = cstring.pop();

		assert(cresult == 'c');

		cresult = cstring.pop();

		assert(cresult == 'b');

		cresult = cstring.pop();

		assert(cresult == 'a');
		//////////////////////////////////////////
	}

	std::cout << "Done Testing Push Pop" << std::endl;
}