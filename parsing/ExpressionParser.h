//
// Created by alexey on 17/04/2020.
//

#ifndef BASICPYTHONINTERPRETER_EXPRESSIONPARSER_H
#define BASICPYTHONINTERPRETER_EXPRESSIONPARSER_H


#include <map>

/*
 * ----------------------------------
 * OVERVIEW
 * ----------------------------------
 *
 * The expression parser reads a string, each char is part of
 * and instance of some category, the categories are as follows:
 *
 * Variables.
 * Binary Operators.
 * Unary operators (left and right operators).
 * Encapsulating operators (e.g. brackets, quotation marks)
 * Integer literals.
 * Whitespace.
 * Integer\double literals.
 * EOL sign (which will be `;`).
 *
 * Also is char is within some breaker class. The amount of breaker
 * classes is subject to change as needed.
 *
 * ----------------------------------
 * CHAR DESIGNATION
 * ----------------------------------
 *
 * If we are under some context (i.e. the last char isn't whitespace)
 * then first we need to check if the current char is valid in
 * continuing this context. A char is a valid continuation of the
 * context only if they are in the same breaker class.
 * The only exception to this is numbers.
 *
 */
class ExpressionParser {

protected:
    std::map<std::string, BinaryExpression> binaryExpr;

    Class* parse(std::string);

};


#endif //BASICPYTHONINTERPRETER_EXPRESSIONPARSER_H
