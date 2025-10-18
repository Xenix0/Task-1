#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include "dynamic_array.h"
#include "Stack.h"
#include <clocale>

using std::string;
using std::cout;
using std::cin;
using std::endl;

dynamic_array<string> token_size(const string& expression) {
	dynamic_array<string> tokens;
	std::stringstream ss(expression);
	string token;
	while (ss >> token) {
		tokens.push_back(token);
	}
	return tokens;
}

bool is_operator(const string& token) {
	return token == "+" || token == "-" || token == "/" || token == "*" || token == "^";
}

bool is_function(const string& token) {
	return token == "sin" || token == "cos";
}

int get_precedence(const string& op) {
	if (op == "^") return 4;
	if (op == "*" || op == "/") return 3;
	if (op == "+" || op == "-") return 2;
	return 0;
}

dynamic_array<string> infix_to_rpn(dynamic_array<string>& tokens) {
	Stack<string> op_stack;
	dynamic_array<string> output;

	for (unsigned i = 0; i < tokens.get_size(); ++i) {
		const string& token = tokens[i];

		if (isdigit(token[0])) {
			output.push_back(token);
		}
		else if (is_function(token)) {
			op_stack.push(token);
		}
		else if (is_operator(token)) {
			while (!op_stack.empty() && is_operator(op_stack.top()) && get_precedence(op_stack.top()) >= get_precedence(token)) {
				output.push_back(op_stack.top());
				op_stack.pop();
			}
			op_stack.push(token);
		}
		else if (token == "(") {
			op_stack.push(token);
		}
		else if (token == ")") {
			while (!op_stack.empty() && op_stack.top() != "(") {
				output.push_back(op_stack.top());
				op_stack.pop();
			}
			if (!op_stack.empty() && op_stack.top() == "(") {
				op_stack.pop();
			}
		}
	}
	while (!op_stack.empty()) {
		output.push_back(op_stack.top());
		op_stack.pop();
	}

	return output;
}

float evaluate_rpn(dynamic_array<string>& rpn) {
	Stack<float> st;

	for (unsigned i = 0; i < rpn.get_size(); ++i) {
		const string& token = rpn[i];

		if (isdigit(token[0])) {
			st.push(std::stof(token));
		}
		else if (is_operator(token)) {
			float b = st.top();
			st.pop();
			float a = st.top();
			st.pop();
			float rez = 0;

			if (token == "+") rez = a + b;
			else if (token == "-") rez = a - b;
			else if (token == "*") rez = a * b;
			else if (token == "/") rez = a / b;
			else if (token == "^") rez = std::pow(a, b);

			st.push(rez);
		}

		else if (is_function(token)) {
			float a = st.top(); 
			st.pop();
			if (token == "sin") st.push(std::sin(a));
			if (token == "cos") st.push(std::cos(a));

		}
	}

	return st.top();
}

int main() {
	std::setlocale(LC_ALL, "ru");

	cout << "Введите выражение (через пробел)\n";
	string expression;
	std::getline(cin, expression);

	dynamic_array<string> tokens = token_size(expression);
	dynamic_array<string> rpn = infix_to_rpn(tokens);

	cout << "Обратная польская нотация: ";
	for (unsigned i = 0; i < rpn.get_size(); ++i) {
		cout << rpn[i] << " ";
	}
	cout << endl;

	float result = evaluate_rpn(rpn);
	cout << "Результат: " << result << endl;

	return 0;
}