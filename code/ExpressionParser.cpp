//
// Created by alexey on 24/10/2019.
//

#include "ExpressionParser.h"
#include "../data/datatypes/primitive/PyString.h"
#include "../data/datatypes/AnonymousObject.h"
#include "../data/datatypes/natives/binary/PointerAssignOperator.h"
#include "../data/IOR.h"
#include <algorithm>
#include <vector>
#include <list>

ExpressionParser::ExpressionParser() {
    specialChars.push_back('"');
    specialChars.push_back('\'');
    specialChars.push_back('+');
    specialChars.push_back('-');
    specialChars.push_back('*');
    specialChars.push_back('/');
    specialChars.push_back('\\');
    specialChars.push_back(' ');
    specialChars.push_back('&');
    specialChars.push_back('|');
    specialChars.push_back('=');
    specialChars.push_back('(');
    specialChars.push_back(')');
    specialChars.push_back('!');

    operations.push_back(new PointerAssignOperator());
}

PyObject* ExpressionParser::parseExpression(stringIter_t& startOfExpr, stringIter_t endOfExpr) {

    std::list<PyObject*> splatData{getSubExpr(startOfExpr, endOfExpr)};

    if (splatData.empty()){
        IOR::getInstance().getErr().emplace_back("Expression expected but not found!");
        return nullptr;
    }

    bool didSomething;
    while(splatData.size() != 1){
        didSomething = false;
        for (auto obj = splatData.begin(); obj != splatData.end(); ++obj){
            for (auto& oper : operations){
                if (oper->getType() == "binary_native"){
                    if (obj == splatData.begin()){
                        IOR::getInstance().getErr().emplace_back(
                                "Found binary operator at the start of an expression");
                        return nullptr;
                    }
                    auto* asBin = (BinaryNativeFunction*)oper;
                    auto objBefore = --obj;
                    (obj++)++;
                    PyObject* newObj = asBin->execute(*(objBefore), *obj); // TODO bruh
                    obj++;
                } else if (oper->getType() == "unary_native"){
                    // TODO
                }
            }
        }
    }

    // TODO delete all anonymous objects

    return splatData.front();

}

std::list<PyObject*> ExpressionParser::getSubExpr(stringIter_t& startOfExpr, stringIter_t endOfExpr) {
    std::list<PyObject*> ret;
    std::string temp;

    for (auto it = startOfExpr; it != endOfExpr; it++){

        if (*it.base() == ' ') // Ignore all whitespace
            continue;

        switch (*it.base()){
            case '=':
                ret.push_back(new PointerAssignOperator());
                break;
            case '"':
                it++;

                while (*it.base() != '"'){
                    temp.push_back(*it.base());
                    ++it;
                    if (it == endOfExpr){
                        return std::list<PyObject*>{};
                    }
                }
                ret.push_back(new AnonymousObject(new PyString(std::move(temp))));
                break;
            default:
                ret.push_back(readVariableName(it, endOfExpr));
                it--;
                break;
        }

        temp = std::string();

    }

    return std::move(ret);
}

PyObject *ExpressionParser::readVariableName(stringIter_t& iter, stringIter_t& end) {
    std::string varName;
    while(iter != end){
        for (auto& c: specialChars){
            if (c == *iter.base()) goto endOfWhile;
        }
        varName.push_back(*iter.base());
        iter++;
    }
    endOfWhile:

    return Memory::getInstance().getVariable(varName);
}

ExpressionParser::~ExpressionParser() {
    for (auto& o : operations){
        delete(o);
    }
}
