//
// Created by alexey on 28/10/2019.
//

#include "Var.h"
#include <memory>
#include "../ExpressionParser.h"
#include "../../data/IOR.h"
#include "../../data/datatypes/AnonymousObject.h"

stringIter_t &Var::parse(stringIter_t &ip, stringIter_t &end) {

    std::string varName;
    PyObject* toAlloc = new AnonymousObject(new PyObject("null"));

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
            IOR::getInstance().getErr().emplace_back("Var name can't start with number");
            deleteIfRValue(toAlloc);
            return end;
        default:
            break;
    }

    for (; ip != end; ip++){
        if (*ip.base() == ' ' || *ip.base() == '='){
            if (*ip.base() == ' ') ip++;
            while (ip != end){
                if (*ip.base() == '='){

                    delete(toAlloc);
                    toAlloc = ExpressionParser::getInstance().parseExpression(++ip, end);
                    ip = end;

                } else if (*ip.base() != ' '){

                    IOR::getInstance().getErr().emplace_back("Illegal char in var name");
                    deleteIfRValue(toAlloc);
                    return end;

                }
            }
            goto alloc;
        }

        for (char& l : ExpressionParser::getInstance().specialChars){
            if (*ip.base() == l){
                IOR::getInstance().getErr().emplace_back("Illegal char in var name");
                deleteIfRValue(toAlloc);
                return end;
            }
        }
        varName.push_back(*ip.base());
    }
    alloc:

    if (toAlloc == nullptr) return end;

    if (toAlloc->getType() == "rvalue"){

        PyObject* released = toAlloc;
        toAlloc = nullptr;
        PyObject* inner = ((AnonymousObject*)(released))->getObj();

        int pointer = Memory::getInstance().alloc(inner);
        if (pointer == -1){
            IOR::getInstance().getErr().emplace_back("Couldn't allocate variable");
            delete(released);
            return end;
        }
        Memory::getInstance().allocPointer(varName, pointer);
        delete(released);
    } else {
        Memory::getInstance().allocPointer(varName, Memory::getInstance().getPointerByObject(&(*toAlloc)));
    }
    deleteIfRValue(toAlloc);
    return end;
}

Var::Var() : AbstractKeyword("var") {

}

void Var::deleteIfRValue(PyObject * o) {
    if (o != nullptr && o->getType() == "rvalue"){
        delete(o);
    }
}
