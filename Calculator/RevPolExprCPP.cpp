//Definition of functions to convert expression into reverse poland notation
#include "StructuresH.h"
#include "StackH.h"

using namespace Structures;
using namespace StackFunc;
using namespace std;

namespace RevPolExpr
{

    Elem dtrmElem(string expr, int i)
    {
        //Check if it is unary operand and, if so, we should determine it with a digit as a whole number instead of operation 
        if (((expr[i] == '+') || (expr[i] == '-')) && ((expr[i + 1] >= '0') && (expr[i + 1] <= '9')) && ((i - 1 < 0) || ((expr[i - 1] <= '0') || (expr[i - 1] >= '9'))))
        {
            int temp = i;
            temp -= 1;
            while ((temp >= 0) && (expr[temp] == ')'))
            {
                temp--;
            }
            if ((temp < 0) || ((expr[temp] < '0') || (expr[temp] > '9')))
            {
                return num;
            }
        }

        switch (expr[i])
        {
        case '+':
            return plusik;
        case '-':
            return minusik;
        case '*':
            return mult;
        case '/':
            return divsn;
        case '^':
            return power;
        case '(':
            return lBrct;
        case ')':
            return rBrct;
        default:
            return num;
        }
    }

    string getElem(string expr, int* i)
    {
        string elem;
        if (((expr[*i] == '-') || (expr[*i] == '+')) && (dtrmElem(expr, *i) == num))
        {
            elem += expr[*i];
            *i += 1;
        }
        if (dtrmElem(expr, *i) == num)
        {
            while (((expr[*i] >= '0') && (expr[*i] <= '9')) || (expr[*i] == '.'))
            {
                elem += expr[*i];
                *i += 1;
            }
            return elem;
        }
        else
        {
            elem = expr[*i];
            *i += 1;
            return elem;
        }
    }

    int getRelPrior(Elem symb)
    {
        switch (symb)
        {
        case plusik:
            return 1;
        case minusik:
            return 1;
        case mult:
            return 3;
        case divsn:
            return 3;
        case power:
            return 6;
        case num:
            return 7;
        case lBrct:
            return 9;
        default:
            return 0;
        }
    }

    int getStackPrior(Elem symb)
    {
        switch (symb)
        {
        case plusik:
            return 2;
        case minusik:
            return 2;
        case mult:
            return 4;
        case divsn:
            return 4;
        case power:
            return 5;
        case num:
            return 8;
        case lBrct:
            return 0;
        default:
            return 0;
        }
    }

    string revPolExpr(string expr)
    {
        elmnt stack = new list;
        stack->next = nullptr;
        string newExpr;
        int i{ 0 };
        while (i <= expr.length() - 1)
        {
            Elem dtrm = dtrmElem(expr, i);
            if ((isEmpty(stack)) || (getRelPrior(dtrm) > getStackPrior(dtrmElem(stack->elem, 0))))
            {
                stack = push(stack, getElem(expr, &i));
            }
            else
            {
                if (dtrmElem(expr, i) == rBrct)
                {
                    string temp;
                    while (dtrmElem(top(stack), 0) != lBrct)
                    {
                        stack = pop(stack, &temp);
                        newExpr = newExpr + ' ' + temp;
                    }
                    stack = pop(stack, &temp);
                    i++;
                }
                else
                {
                    string temp;
                    while (!isEmpty(stack) && (getRelPrior(dtrm) < getStackPrior(dtrmElem(stack->elem, 0))))
                    {
                        stack = pop(stack, &temp);
                        newExpr = newExpr + ' ' + temp;
                    }
                    stack = push(stack, getElem(expr, &i));
                }
            }
        }
        while (!isEmpty(stack))
        {
            string temp;
            stack = pop(stack, &temp);
            newExpr = newExpr + ' ' + temp;
        }

        return newExpr;
    }

}