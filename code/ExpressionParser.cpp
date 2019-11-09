//
// Created by alexey on 24/10/2019.
//

#include "ExpressionParser.h"
#include "../data/datatypes/primitive/PyString.h"
#include "../data/datatypes/natives/binary/PointerAssignOperator.h"
#include "../data/IOR.h"
#include "../util/LinkedList.h"
#include "../data/datatypes/natives/binary/AdditionOperator.h"
#include "../data/datatypes/primitive/PyFunction.h"
#include "../data/datatypes/natives/binary/EqualityCheckOperator.h"
#include "../data/datatypes/primitive/PyInteger.h"
#include "../data/datatypes/natives/binary/MultiplicationOperator.h"
#include "../data/datatypes/natives/binary/SubtractionOperator.h"

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
    specialChars.push_back(',');

# define multI 0
    operations.push_back(new MultiplicationOperator());
# define addI 1
    operations.push_back(new AdditionOperator());
# define subI 2
    operations.push_back(new SubtractionOperator());
# define eqI 3
    operations.push_back(new EqualityCheckOperator());
# define assingI 4
    operations.push_back(new PointerAssignOperator());

}

int ExpressionParser::parseExpression(stringIter_t& startOfExpr, stringIter_t endIt) {
    const char noTerminator = '\0';
    return parseExpression(startOfExpr, endIt, &noTerminator);
}

int ExpressionParser::parseExpression(stringIter_t& startOfExpr, stringIter_t endIt, const char* endChar) {

    LinkedList<PyObject*> splatData{getSubExpr(startOfExpr, endIt, endChar)};

    if (splatData.empty()){
//        IOR::getInstance().reportError("Expression expected but not found!");
        return -1;
    }

    bool didSomething;

    while(splatData.size() != 1){

        didSomething = false;

        for (PyObject* oper : operations){

            for (auto obj = splatData.getStart(); obj != nullptr; obj = obj->next){

                if (oper->getType() == "binary_native" && oper == obj->value){

                    if (obj == splatData.getStart() || obj == splatData.getEnd()){
                        IOR::getInstance().reportError(
                                "Found binary operator at the start or end of an expression");
                        return -1;
                    }

                    auto* asBin = (BinaryNativeFunction*)obj->value;
                    if (asBin->getName() != ((BinaryNativeFunction*)oper)->getName()) continue;
                    auto* prev = obj->prev;
                    auto* next = obj->next;

                    PyObject* newObj = asBin->execute(prev->value, next->value);

                    if (newObj == nullptr){
                        safelyClear(splatData);
                        IOR::getInstance().reportError("Execution of operator " + asBin->getName() + " failed.");
                        return -1;
                    }

                    auto* newNode = new Node<PyObject*>(newObj);

                    splatData.connectAfter(obj, newNode);
                    disconnectSafely(splatData, prev);
                    disconnectSafely(splatData, next);
                    disconnectSafely(splatData, obj);

                    didSomething = true;
                    break;

                } else if (oper->getType() == "unary_native" && oper == obj->value){
                    // TODO
                }
            }
            if (didSomething) break;
        }

        if (!didSomething) {
            IOR::getInstance().reportError(
                    "Couldn't collapse expression");
            // Run clean nup
            safelyClear(splatData);

            return -1;
        }

    }

    PyObject* ret = splatData.getStart()->value;
    splatData.disconnectAndKeepAlive(0);

    int retPointer;

    if (ret->getType() == "rvalue"){
#if OBJECT_DEBUG == true
        IOR::getInstance().reportDebug("Added anon to mem for treatment by GC");
#endif
        PyObject* temp = ret;
        ret = ret->yoink();
        delete(temp);
        retPointer = Memory::getInstance().alloc(ret); // Let the garbage collector deal with it when needed.
    } else {
        retPointer = Memory::getInstance().getPointerByObject(ret);
    }

    return retPointer;

}

LinkedList<PyObject*> ExpressionParser::getSubExpr(stringIter_t& startOfExpr, stringIter_t& endIt, const char* endChar) {
    LinkedList<PyObject*> ret;
    std::string temp;

    for (stringIter_t& it = startOfExpr; it != endIt; it++){


        if (*it.base() == ' ') // Ignore all whitespace
            continue;
        // Make sure end char is not seen
        const char* tempP = endChar;
        while (*tempP != '\0'){
            if (*tempP == *it.base())
                return std::move(ret);
            tempP++;
        }


        switch (*it.base()){
            case '=':
                ++it;
                if (*(it).base() == '='){
                    ret.addToBackV(operations.at(eqI)); // e for equality
                    break;
                }
                --it;
                ret.addToBackV(operations.at(assingI));
                break;
            case '+':
                ret.addToBackV(operations.at(addI));
                break;
            case '*':
                ret.addToBackV(operations.at(multI));
                break;
            case '-':
                ret.addToBackV(operations.at(subI));
                break;
            case '"':
                it++;

                while (*it.base() != '"'){
                    temp.push_back(*it.base());
                    if (it == endIt){
                        safelyClear(ret);
                        IOR::getInstance().reportError("Couldn't find \" to end string");
                        return LinkedList<PyObject*>{};
                    }
                    ++it;
                }
                ret.addToBackV(new AnonymousObject(new PyString(temp)));
                break;
            default:

                if (!isNumber(it.base())) {
                    ret.addToBackV(readVariableName(it, endIt));
                    if (ret.getEnd()->value == nullptr) {
                        safelyClear(ret);
                        return LinkedList<PyObject *>{};
                    }
                    if (ret.getEnd()->value->getType() == "func") {
                        funcTryReply_t ran = tryRunFunction(ret.getEnd()->value, it, endIt);
                        Memory::getInstance().enableGC();
                        if (ran.second.first) {
                            it = ran.second.second;
                            ret.getEnd()->value = ran.first;
                        }
                    }
                    it--;
                } else {

                    std::string tempInt;
                    while(it != endIt && isNumber(it.base())){
                        tempInt.push_back(*it.base());
                        it++;
                    }
                    it--;

                    ret.addToBackV(new AnonymousObject(new PyInteger(atoi(tempInt.c_str()))));
                }
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

    PyObject* obj = Memory::getInstance().getVariable(varName);

    if (obj == nullptr){
        IOR::getInstance().reportError("Couldn't find variable with name: " + varName);
    }

    return obj;
}

ExpressionParser::~ExpressionParser() {
    for (PyObject*& o : operations){
        delete(o);
        o = nullptr;
    }
}

void ExpressionParser::disconnectSafely(LinkedList<PyObject *> &ls, Node<PyObject*>* val) {
    if (val->value == nullptr){
        ls.disconnect(val);
        return;
    }
    auto& v = val->value->getType();
    if (v == "rvalue"){
        ls.disconnect(val);
    } else {
        ls.disconnectAndKeepAlive(val);
    }
}

funcTryReply_t
ExpressionParser::tryRunFunction(PyObject* func, stringIter_t it, const stringIter_t &end) {
    if (func->getType() != "func"){
        return {nullptr, {false, end}};
    }
    if (*it.base() != '('){
        return {nullptr, {false, end}};
    }

    // Get all vars
    std::vector<PyObject*> vars;
    char stoppers[2] = {',', ')'};
    bool noInp = true;

    Memory::getInstance().disableGC();

    while (it != end){
        it++;

        int ptr = parseExpression(it, end, stoppers);

        if (ptr == -1){
            if (noInp && *it.base() == ')'){
                break;
            }
            return {nullptr, {false, end}};
        }

        vars.push_back(Memory::getInstance().getData().at(ptr));
        if (*it.base() == ')') break;

        noInp = false;
    }

    if (it == end){
        return {nullptr, {false, end}};
    }

    Memory::getInstance().enableGC();

#if FUNCTION_DEBUG == true
    IOR::getInstance().reportDebug("Running function, current depth = " + std::to_string(Memory::getInstance().depth + 1));
#endif

    PyFunction* asF = (PyFunction*)func;

    PyObject* ret = asF->execute(vars);

#if FUNCTION_DEBUG == true
    IOR::getInstance().reportDebug("Exiting function, current depth = " + std::to_string(Memory::getInstance().depth));
#endif


    if (ret == nullptr) {
        return {nullptr, {false, end}};
    }

    return {ret, {true, ++it}};
}

void ExpressionParser::safelyClear(LinkedList<PyObject *> &ls) {
    while(ls.getStart() != nullptr){
        disconnectSafely(ls, ls.getStart());
    }
}

bool ExpressionParser::isNumber(const char *c) {
    return *c >= 0x30 && *c <= 0x39;
}