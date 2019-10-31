//
// Created by alexey on 24/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_EXPRESSIONPARSER_H
#define BASICPYTHONINTERPRETER_EXPRESSIONPARSER_H


#include <vector>
#include <list>
#include "../data/datatypes/PyObject.h"
#include "../data/Memory.h"
#include "../util/LinkedList.h"

typedef std::pair<PyObject *, std::pair<bool, stringIter_t>> funcTryReply_t;

class ExpressionParser {
private:
    ExpressionParser();
    /**
     * Returns a list for easy deletion and replacement of elements.
     * @param startOfExpr
     * @param endOfExpr
     * @return
     */
    LinkedList<PyObject *> getSubExpr(stringIter_t& startOfExpr, stringIter_t& endOfExpr);
    /**
     *
     * If a variable is a variable, return it's value. If it's a function, attempt to execute it. If you
     * can't, treat it as a variable
     *
     * @param start The beginning of the variable
     * @param end The end of the line
     * @return The variable
     */
    PyObject* readVariableName(stringIter_t& start, stringIter_t& end);
    /**
     * Remove values from linked list, delete if they are rvalues
     * @param ls
     * @param val
     */
    void disconnectSafely(LinkedList<PyObject *> &ls, Node<PyObject *> *val);


    funcTryReply_t tryRunFunction(PyObject* funcName, stringIter_t start, const stringIter_t& end);


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
    std::map<char, PyObject*> operations;

};


#endif //BASICPYTHONINTERPRETER_EXPRESSIONPARSER_H
