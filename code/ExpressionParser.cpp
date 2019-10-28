//
// Created by alexey on 24/10/2019.
//

#include "ExpressionParser.h"
#include "../data/datatypes/primitive/PyString.h"
#include "../data/datatypes/AnonymousObject.h"
#include "../data/datatypes/natives/binary/PointerAssignOperator.h"
#include "../data/IOR.h"
#include "../util/LinkedList.h"

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

    LinkedList<PyObject*> splatData{getSubExpr(startOfExpr, endOfExpr)};

    if (splatData.empty()){
        IOR::getInstance().getErr().emplace_back("Expression expected but not found!");
        return nullptr;
    }

    bool didSomething;

    while(splatData.size() != 1){

        didSomething = false;

        for (auto obj = splatData.getStart(); obj != nullptr; obj = obj->next){
            for (auto& oper : operations){
                if (oper->getType() == "binary_native" && oper->getType() == obj->value->getType()){

                    if (obj == splatData.getStart() || obj == splatData.getEnd()){
                        IOR::getInstance().getErr().emplace_back(
                                "Found binary operator at the start or end of an expression");
                        return nullptr;
                    }
                    auto* asBin = (BinaryNativeFunction*)obj->value;
                    if (asBin->getName() != ((BinaryNativeFunction*)oper)->getName()) continue;
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

                } else if (oper->getType() == "unary_native"){
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

    // TODO delete all anonymous objects
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
            case ' ':
                continue;
            case '=':
                ret.addToBackV(new PointerAssignOperator());
                break;
            case '"':
                it++;

                while (*it.base() != '"'){
                    temp.push_back(*it.base());
                    ++it;
                    if (it == endOfExpr){
                        return LinkedList<PyObject*>{};
                    }
                }
                ret.addToBackV(new AnonymousObject(new PyString(temp)));
                break;
            default:
                ret.addToBackV(readVariableName(it, endOfExpr));
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

void ExpressionParser::disconnectSafely(LinkedList<PyObject *> &ls, Node<PyObject*>* val) {
    auto& v = val->value->getType();
    if (v == "rvalue" || v == "binary_native"){
        ls.disconnect(val);
    } else {
        ls.disconnectAndKeepAlive(val);
    }
}
