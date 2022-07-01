//Definition of functions to work with stack
#include <string>
#include "StructuresH.h"

//Optional function, unnecessary in this implementation
/*
elmnt createStack(elmnt head)
{
    head = new list;
    head->next = nullptr;
    return head;
}
*/

using namespace Structures;
using namespace std;

namespace StackFunc
{

    bool isEmpty(elmnt head)
    {
        return (head->next == nullptr);
    }

    elmnt push(elmnt head, string str)
    {
        elmnt newElem = new list;
        newElem->next = head;
        head = newElem;
        head->elem = str;
        return head;
    }

    elmnt pop(elmnt head, string* str)
    {
        *str = head->elem;
        elmnt temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    string top(elmnt head)
    {
        return head->elem;
    }

}


