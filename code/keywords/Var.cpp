//
// Created by alexey on 28/10/2019.
//

#include "Var.h"
#include "../ExpressionParser.h"
#include "../../data/IOR.h"

stringIter_t &Var::parse(stringIter_t &ip, stringIter_t &end) {

    std::string varName;
    auto* toAlloc = new PyObject("null");

    for (; ip != end; ip++){
        if (*ip.base() == ' ' || *ip.base() == '='){
            if (*ip.base() == ' ') ip++;
            while (ip != end){
                if (*ip.base() == '='){

                    delete(toAlloc);
                    toAlloc = ExpressionParser::getInstance().parseExpression(++ip, end);
                    ip = end;

                } else if (*ip.base() != ' '){

                    delete(toAlloc);
                    IOR::getInstance().getErr().emplace_back("Illegal char in var name");
                    return end;

                }
            }
            goto alloc;
        }

        for (char& l : ExpressionParser::getInstance().specialChars){
            if (*ip.base() == l){
                IOR::getInstance().getErr().emplace_back("Illegal char in var name");
                return end;
            }
        }
        varName.push_back(*ip.base());
    }
    alloc:
    int pointer = Memory::getInstance().alloc(*toAlloc);
    Memory::getInstance().allocPointer(varName, pointer);
}

Var::Var() : AbstractKeyword("var") {

}
