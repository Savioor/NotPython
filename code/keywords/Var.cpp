//
// Created by alexey on 28/10/2019.
//

#include "Var.h"
#include <memory>
#include "../ExpressionParser.h"
#include "../../data/IOR.h"
#include "../../data/datatypes/AnonymousObject.h"

stringIter_t &Var::parse(stringIter_t &ip, stringIter_t &end, IRequester& req) {

    std::string varName;
    int toAlloc = -2;

    char first = *ip.base();
    switch (first){
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '0':
            IOR::getInstance().reportError("Var name can't start with number");
            return end;
        default:
            break;
    }

    for (; ip != end; ip++){
        if (*ip.base() == ' ' || *ip.base() == '='){
            if (*ip.base() == ' ') ip++;
            while (ip != end){
                if (*ip.base() == '='){

                    toAlloc = ExpressionParser::getInstance().parseExpression(++ip, end);
                    ip = end;

                } else if (*ip.base() != ' '){

                    IOR::getInstance().reportError("Illegal char in var name");
                    return end;

                }
            }
            goto alloc;
        }

        for (char& l : ExpressionParser::getInstance().specialChars){
            if (*ip.base() == l){
                IOR::getInstance().reportError("Illegal char in var name");
                return end;
            }
        }
        varName.push_back(*ip.base());
    }
    alloc:

    if (toAlloc == -1) return end;
    if (Memory::getInstance().getVariable(varName) != nullptr){
        IOR::getInstance().reportError("Variable already defined");
        return end;
    }

    if (toAlloc == -2){
        toAlloc = Memory::getInstance().alloc(new PyObject("null"));
    }

    Memory::getInstance().allocPointer(varName, toAlloc);

    return end;
}

Var::Var() : AbstractKeyword("var") {

}

