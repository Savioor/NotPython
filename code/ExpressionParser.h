//
// Created by alexey on 24/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_EXPRESSIONPARSER_H
#define BASICPYTHONINTERPRETER_EXPRESSIONPARSER_H


#include <vector>
#include "../data/datatypes/PyObject.h"
#include "../data/Memory.h"

class ExpressionParser {
private:
    ExpressionParser();
    std::vector<char> specialChars;

public:
    static ExpressionParser& getInstance() {
        static ExpressionParser instance;
        return instance;
    }
    PyObject * parseExpression(stringIter_t& startOfExpr, stringIter_t endOfExpr);

    std::vector<PyObject*> getSubExpr(stringIter_t& startOfExpr, stringIter_t endOfExpr);

};


#endif //BASICPYTHONINTERPRETER_EXPRESSIONPARSER_H
