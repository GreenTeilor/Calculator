//Declaration of functions to work with stack
#pragma once
#include "StructuresH.h"
#include <string>

namespace StackFunc
{
	using namespace std;
	using namespace Structures;
	bool isEmpty(elmnt head);
	elmnt push(elmnt head, string str);
	elmnt pop(elmnt head, string* str);
	string top(elmnt head);
}
