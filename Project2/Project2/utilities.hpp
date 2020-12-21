
#include "stack.hpp"
#include "string.hpp"
#include <iostream>

void evaluate_postfix(String, String, String, int, std::ostream&);
void evaluate_prefix(String, String, String, int, std::ostream&);
String int_to_string(int);
void reverseString(String&, int, int);

void infix_to_postfix(std::istream& in, std::ostream& out) {

	while (!in.eof()) {

		stack<String> S;
		String left, right, op, token;
		in >> token;

		while (token != ';') {

			if (token == ')') {

				right = S.pop();
				op = S.pop();
				left = S.pop();
				S.push(left + right + op);

			}
			else if (token != '(')
				S.push(token + " ");

			in >> token;

		}

		out << S.pop();
		out << ";" << std::endl;

		in.ignore();


	}

}

void infix_to_prefix(std::istream& in, std::ostream& out) {

	while (!in.eof()) {

		stack<String> S;
		String left, right, op, token;
		in >> token;

		while (token != ';') {

			if (token == ')') {

				right = S.pop();
				op = S.pop();
				left = S.pop();
				S.push(op + left + right);

			}
			else if (token != '(')
				S.push(token + " ");

			in >> token;

		}

		out << S.pop();
		out << ";" << std::endl;

		in.ignore();

	}

}

void postfix_to_assembly(std::istream& in, std::ostream& out) {

	stack<String> S;
	String left, right, op, token;
	int tmpCount = 0;
	in >> token;

	while (token != ';') {

		if (token != "+" && token != "-" && token != "*" && token != "/")
			S.push(token);
		else {
			right = S.pop();
			left = S.pop();

			evaluate_postfix(left, token, right, ++tmpCount, out);

			S.push("TMP" + int_to_string(tmpCount));

		}

		in >> token;

	}

	out << std::endl;

}



void evaluate_postfix(String left, String t, String right, int tmpCount, std::ostream& out) {

	out << "   " << "LD     " << left << std::endl;

	switch (t[0]) {
	case '+':
		out << "   " << "AD     ";
		break;
	case '-':
		out << "   " << "SB     ";
		break;
	case '*':
		out << "   " << "MU     ";
		break;
	case '/':
		out << "   " << "DV     ";
		break;
	default:
		out << "   " << "UNDEFINED     ";
	}

	out << right << std::endl;

	out << "   " << "ST     TMP" << tmpCount << std::endl;

}



void prefix_to_assembly(std::istream& in, std::ostream& out) {

	stack<String> S;
	String left, right, op, token;
	int tmpCount = 0;

	String fStr;
	while (token != ';') {
		in >> token;
		fStr += " " + token;
	}

	int i = 1;

	reverseString(fStr, 0, fStr.length());

	std::vector<String> vecStr = fStr.split(' ');

	while (vecStr[i] != "") {

		if (vecStr[i].length() > 1) {
			char temp = vecStr[i][0];
			vecStr[i][0] = vecStr[i][1];
			vecStr[i][1] = temp;
		}

		if (vecStr[i] != '+' && vecStr[i] != '-' && vecStr[i] != '*' && vecStr[i] != '/')
			S.push(vecStr[i]);
		else {
			left = S.pop();
			right = S.pop();

			evaluate_prefix(left, vecStr[i], right, ++tmpCount, out);

			S.push("TMP" + int_to_string(tmpCount));

		}

		++i;

	}

	out << std::endl;

}

void evaluate_prefix(String left, String t, String right, int tmpCount, std::ostream& out) {

	out << "   " << "LD     " << left << std::endl;

	switch (t[0]) {
	case '+':
		out << "   AD     ";
		break;
	case '-':
		out << "   SB     ";
		break;
	case '*':
		out << "   MU     ";
		break;
	case '/':
		out << "   DV     ";
		break;
	default:
		out << "   UNDEFINED     ";
	}

	out << right << std::endl;

	out << "   ST     TMP" << tmpCount << std::endl;

}


String int_to_string(int x) {

	String result;

	while (x > 0) {
		result += char(x % 10 + 48);
		x /= 10;
	}

	return result;

}

void reverseString(String& str, int start, int end)
{
	while (start < end)
	{
		int temp = str[start];
		str[start] = str[end - 1];
		str[end - 1] = temp;
		++start;
		--end;
	}
}