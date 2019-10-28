//
// Created by alexey on 24/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_EXPRESSIONPARSER_H
#define BASICPYTHONINTERPRETER_EXPRESSIONPARSER_H


#include <vector>
#include <list>
#include "../data/datatypes/PyObject.h"
#include "../data/Memory.h"

class ExpressionParser {
private:
    ExpressionParser();
    /**
     * Returns a list for easy deletion and replacement of elements.
     * @param startOfExpr
     * @param endOfExpr
     * @return
     */
    std::__cxx11::list<PyObject *> getSubExpr(stringIter_t& startOfExpr, stringIter_t endOfExpr);
    PyObject* readVariableName(stringIter_t& start, stringIter_t& end);


public:
    virtual ~ExpressionParser();

    static ExpressionParser& getInstance() {
        static ExpressionParser instance;
        return instance;
    }
    PyObject * parseExpression(stringIter_t& startOfExpr, stringIter_t endOfExpr);
    std::vector<char> specialChars;
    /**
     * The first operations happen first
     */
    std::vector<PyObject*> operations;
};


#endif //BASICPYTHONINTERPRETER_EXPRESSIONPARSER_H
