//
// Created by alexey on 24/10/2019.
//

#include "ExpressionParser.h"
#include "../data/datatypes/primitive/PyString.h"
#include "../data/datatypes/AnonymousObject.h"
#include "../data/datatypes/natives/binary/PointerAssignOperator.h"
#include "../data/IOR.h"
#include "../util/LinkedList.h"
#include "../data/datatypes/natives/binary/AdditionOperator.h"

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

    operations.insert({'=', new PointerAssignOperator()});
    operations.insert({'+', new AdditionOperator()});
}

PyObject* ExpressionParser::parseExpression(stringIter_t& startOfExpr, stringIter_t endOfExpr) {

    LinkedList<PyObject*> splatData{getSubExpr(startOfExpr, endOfExpr)};

    if (splatData.empty()){
//        IOR::getInstance().getErr().emplace_back("Expression expected but not found!");
        return nullptr;
    }

    bool didSomething;

    while(splatData.size() != 1){

        didSomething = false;

        for (std::pair<const char, PyObject*>& oper : operations){
            for (auto obj = splatData.getStart(); obj != nullptr; obj = obj->next){
                if (oper.second->getType() == "binary_native" && oper.second == obj->value){

                    if (obj == splatData.getStart() || obj == splatData.getEnd()){
                        IOR::getInstance().getErr().emplace_back(
                                "Found binary operator at the start or end of an expression");
                        return nullptr;
                    }

                    auto* asBin = (BinaryNativeFunction*)obj->value;
                    if (asBin->getName() != ((BinaryNativeFunction*)oper.second)->getName()) continue;
                    auto* prev = obj->prev;
                    auto* next = obj->next;

                    PyObject* newObj = asBin->execute(prev->value, next->value);
                    auto* newNode = new Node<PyObject*>(newObj);

                    splatData.connectAfter(obj, newNode);
                    disconnectSafely(splatData, prev);
                    disconnectSafely(splatData, next);
                    disconnectSafely(splatData, obj);

                    didSomething = true;
                    break;

                } else if (oper.second->getType() == "unary_native" && oper.second == obj->value){
                    // TODO
                }
            }
            if (didSomething) break;
        }

        if (!didSomething) {
            IOR::getInstance().getErr().emplace_back(
                    "Couldn't collapse expression");
            return nullptr;
        }

    }

    PyObject* ret = splatData.getStart()->value;
    splatData.disconnectAndKeepAlive(0);

    return ret;

}

LinkedList<PyObject*> ExpressionParser::getSubExpr(stringIter_t& startOfExpr, stringIter_t& endOfExpr) {
    LinkedList<PyObject*> ret;
    std::string temp;

    for (auto it = startOfExpr; it != endOfExpr; it++){

        if (*it.base() == ' ') // Ignore all whitespace
            continue;

        switch (*it.base()){
            case '=':
                ret.addToBackV(operations.at('='));
                break;
            case '+':
                ret.addToBackV(operations.at('+'));
                break;
            case '"':
                it++;

                while (*it.base() != '"'){
                    temp.push_back(*it.base());
                    if (it == endOfExpr){
                        return LinkedList<PyObject*>{};
                    }
                    ++it;
                }
                ret.addToBackV(new AnonymousObject(new PyString(temp)));
                break;
            default:
                ret.addToBackV(readVariableName(it, endOfExpr));
                if (ret.getEnd()->value == nullptr){
                    return LinkedList<PyObject*>{};
                }
                it--;
                break;
        }

        temp = std::string();

    }

    return std::move(ret);
}

PyObject *ExpressionParser::readVariableName(stringIter_t& iter, stringIter_t& end) {
    std::string varName;
    bool atLeastOneLong = false;
    while(iter != end){
        for (auto& c: specialChars){
            if (c == *iter.base()) {
                if (!atLeastOneLong)
                    return nullptr;
                else
                    goto endOfWhile;
            }
        }
        atLeastOneLong = true;
        varName.push_back(*iter.base());
        iter++;
    }
    endOfWhile:

    return Memory::getInstance().getVariable(varName);
}

ExpressionParser::~ExpressionParser() {
    for (std::pair<const char, PyObject*>& o : operations){
        delete(o.second);
    }
}

void ExpressionParser::disconnectSafely(LinkedList<PyObject *> &ls, Node<PyObject*>* val) {
    auto& v = val->value->getType();
    if (v == "rvalue"){
        ls.disconnect(val);
    } else {
        ls.disconnectAndKeepAlive(val);
    }
}
