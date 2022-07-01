//Declaration of functions to convert expression into reverse poland notation
#pragma once
#include "StructuresH.h"


namespace RevPolExpr 
{
	using namespace Structures;
	using namespace std;
	Elem dtrmElem(string expr, int i);
	string getElem(string expr, int* i);
	int getRelPrior(Elem symb);
	int getStackPrior(Elem symb);
	string revPolExpr(string expr);
}
