#include <iostream>
#include <string>
#include <cmath>
#include "CalculationsH.h"

using namespace std;



//Call function to calculate value of expression
int main()
{
    /* string str{revPolExpr("((3.1458+4)*6)/5.91")};
    cout << revPolExpr("((3.1458+4)*6)/5.91") << endl;
    string oper1, oper2;
    char operation;
    findOperands(&oper1, &oper2, &operation, findOperation(str), str);
    calcValue("3.14", "3.14", '+');
    str = replace(str, to_string(calcValue(oper1, oper2, operation)), findOperation(str));
    return 0; */
    string str, errorMsg = "Invalid expression!";
    while (1) 
    {
            cout << "Input expression: ";
            cin >> str;
            cout << "Result: " << Calculations::calculate(str) << endl;
    }
}

