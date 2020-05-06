//
// Created by alexey on 17/04/2020.
//

#include <iostream>
#include "ExpressionParser.h"
#include "operators/binary/Addition.h"
#include "operators/ClassOperator.h"
#include "../memory/builtins/Integer.h"
#include "../debug.h"


Class *ExpressionParser::parse(const std::string&) {


    return nullptr;
}

ExpressionParser::ExpressionParser() {

    breakerClassMap = std::map<char, int>();

    insertToBreakerMap("+-*/%=!&|<>", MATH_AND_LOGIC); // Mathematical and logical operators
    insertToBreakerMap("()[]\"\'{}", ENCAPSULATING); // Enclosing operator, this breaker class breaks itself
    insertToBreakerMap(" \t\r\n", WHITESPACE); // Whitespace
    insertToBreakerMap(".", DOT_OPERATOR); // Literally just the dot operator

    operators = std::map<std::string, Operator*>();

    operators.insert({"+", new Addition()});

    numbers = std::map<char, char>();
    for (const char* c = "1234567890"; *c != '\0'; c++){
        numbers.insert({*c, *c});
    }

}

void ExpressionParser::insertToBreakerMap(const std::string& chars, int cls) {
    for (int i = 0; i < chars.length(); i++){
        breakerClassMap.insert({chars.at(i), cls});
    }
}

std::vector<Operator *>* ExpressionParser::toOperatorList(const std::string& data) {

    auto* returnList = new std::vector<Operator*>();
    int context = WHITESPACE;
    int currContext;
    std::string currentOp;

    for (char c : data) {

#if EXPR_PARSE_DEBUG
        std::cout << "Reading '" << c << "' with current breaker group " << context << std::endl;
#endif
        if (breakerClassMap.count(c) > 0) {
            currContext = breakerClassMap.at(c);
        } else {
            currContext = LEGAL_ALPHABETICAL;
        }

        if (context == LEGAL_ALPHABETICAL && currContext == DOT_OPERATOR && numbers.count(currentOp.at(0)) > 0){
            currentOp += c; // This dot is part of a double representation
        }
        else if (context != currContext || context == ENCAPSULATING) {
            // Context broke let's parse that other piece of shit

#if EXPR_PARSE_DEBUG
            std::cout << "Context swithced. Curr op = " << currentOp << std::endl;
#endif

            Operator* op = toOperator(currentOp, context);

            if (op != nullptr)
                returnList->push_back(op);

            currentOp = c;
        } else {
            currentOp += c; // This char is part of the same "class" so it's part of the same thing
        }

        context = currContext;
    }

    returnList->push_back(toOperator(currentOp, context));

    return returnList;
}

Operator *ExpressionParser::toOperator(const std::string& currentOp, int context) {
    if (context == ENCAPSULATING) {

        // encapsulating operators are hella gay please kill me
        throw "We don't need brackets, right?"; // TODO, obvsly

    } else if (context == LEGAL_ALPHABETICAL) { // This is variables or numbers, handle differently

        if (numbers.count(currentOp.at(0)) > 0) {

            // This must be a number
            if (currentOp.find_first_of('.') == std::string::npos){

                // TODO
                // 1. here `new ClassOperator` is never deleted and creates a mem-leak albeit a small one
                // 2. std::atoi is not ideal but it's fine for now. replace later.
                // Integer
                return
                        new ClassOperator(
                                new Integer(std::atoi(currentOp.c_str()))
                        );

            } else {
                // Double
                // TODO
            }

        } else {

            // This must be a variable
            // TODO

        }

    } else if (context != WHITESPACE) { //Whitespace is literally useless so ignore it

        // This must be an operator
        if (operators.count(currentOp) == 0){
            throw std::runtime_error("Operator not found");
        }
        return operators.at(currentOp);

    }
    return nullptr;
}
