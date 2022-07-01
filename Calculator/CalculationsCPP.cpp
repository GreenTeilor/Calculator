//Definition of functions to calculate value of expression in reverse poland notation
#include "StructuresH.h"
#include "RevPolExprH.h"

using namespace Structures;
using namespace std;
using namespace RevPolExpr;

namespace Calculations
{


    int findOperation(string expr)
    {
        int i{ 1 };
        bool flag{ false };
        while ((i <= (expr.length() - 1)) && ((expr[i + 1] != ' ') || ((expr[i] != '+') && (expr[i] != '-') && (expr[i] != '*') && (expr[i] != '/') && (expr[i] != '^'))))
        {
            i++;
        }
        if (i >= expr.length())
        {
            i--;
        }
        return i;
    }

    void findOperands(string* oper1, string* oper2, char* operation, int operationPos, string expr)
    {
        int i{ operationPos };
        *operation = expr[i];
        i -= 2;
        while (expr[i] != ' ')
        {
            i--;
        }
        string temp;
        i++;
        while (expr[i] != ' ')
        {
            temp += expr[i];
            i++;
        }
        *oper2 = temp;
        i--;
        while (expr[i] != ' ')
        {
            i--;
        }
        i--;
        while (expr[i] != ' ')
        {
            i--;
        }
        i++;
        temp = "";
        while (expr[i] != ' ')
        {
            temp += expr[i];
            i++;
        }
        *oper1 = temp;
    }

    double calcValue(string oper1, string oper2, char operation)
    {
        double dOper1 = stod(oper1, 0);
        double dOper2 = stod(oper2, 0);
        switch (operation)
        {
        case '+':
            return dOper1 + dOper2;
        case '-':
            return dOper1 - dOper2;
        case '*':
            return dOper1 * dOper2;
        case '/':
            return dOper1 / dOper2;
        default:
            return pow(dOper1, dOper2);
        }
    }

    string replace(string expr, string newValue, int operationPos)
    {
        int i{ operationPos };
        i -= 2;
        while (expr[i] != ' ')
        {
            i--;
        }
        i--;
        while (expr[i] != ' ')
        {
            i--;
        }
        i++;
        expr.erase(i, operationPos - i + 1);
        expr.insert(i, newValue);
        return expr;
    }

    int calcSpaces(string expr)
    {
        int sum{ 0 };
        for (int i = 0; i <= expr.length() - 1; i++)
        {
            if (expr[i] == ' ')
                sum++;
        }
        return sum;
    }

    double calculate(string expr)
    {
        expr = revPolExpr(expr);
        string oper1, oper2;
        char operation;
        while (calcSpaces(expr) > 1)
        {
            findOperands(&oper1, &oper2, &operation, findOperation(expr), expr);
            expr = replace(expr, to_string(calcValue(oper1, oper2, operation)), findOperation(expr));
        }
        expr.erase(0, 1);
        return stod(expr, 0);
    }

}