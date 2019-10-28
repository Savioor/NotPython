//
// Created by alexey on 28/10/2019.
//

#include "Var.h"
#include "../ExpressionParser.h"
#include "../../data/IOR.h"

stringIter_t &Var::parse(stringIter_t &ip, stringIter_t &end) {
    ip++;

    std::string varName;

    for (; ip != end; ip++){
        if (*ip.base() == ' ' || *ip.base() == '='){
            if (*ip.base() == ' ') ip++;
            while (ip != end){
                if (*ip.base() == '='){

                    PyObject* newObj = ExpressionParser::getInstance().parseExpression(++ip, end);
                    int pointer = Memory::getInstance().alloc(*newObj);
                    Memory::getInstance().allocPointer(varName, pointer);
                    return end;

                } else if (*ip.base() != ' '){

                    IOR::getInstance().getErr().emplace_back("Illegal char in var name");
                    return end;

                }
            }
        }

        for (char& l : ExpressionParser::getInstance().specialChars){
            if (*ip.base() == l){
                IOR::getInstance().getErr().emplace_back("Illegal char in var name");
                return end;
            }
        }
        varName.push_back(*ip.base());
    }

    int pointer = Memory::getInstance().alloc(*(new PyObject("null")));
    Memory::getInstance().allocPointer(varName, pointer);
}

Var::Var() : AbstractKeyword("var") {

}
