//Declaration of functions to calculate value of expression in reverse poland notation
#pragma once
#include <string>;

namespace Calculations
{
	using namespace std;
	int findOperation(string expr);
	void findOperands(string* oper1, string* oper2, char* operation, int operationPos, string expr);
	double calcValue(string oper1, string oper2, char operation);
	string replace(string expr, string newValue, int operationPos);
	int calcSpaces(string expr);
	double calculate(string expr);
}