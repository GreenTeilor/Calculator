//Declaration of all structures
#pragma once
#include <string>

namespace Structures
{
    enum Elem
    {
        num,
        plusik,
        minusik,
        mult,
        divsn,
        power,
        lBrct,
        rBrct
    };
    struct list
    {
        std::string elem;
        list* next;
    };
}

using elmnt = Structures::list*;

