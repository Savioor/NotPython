//
// Created by alexey on 17/04/2020.
//

#include "ExpressionParser.h"
#include "operators/binary/Addition.h"


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
    for (const char* c = "1234567890"; c != nullptr; c++){
        breakerClassMap.insert({*c, *c});
    }

}

void ExpressionParser::insertToBreakerMap(const std::string& chars, int cls) {
    for (const char* c = chars.c_str(); c != nullptr; c++){
        breakerClassMap.insert({*c, cls});
    }
}

std::vector<Operator *>* ExpressionParser::toOperatorList(const std::string& data) {

    auto* returnList = new std::vector<Operator*>();
    int context = WHITESPACE;
    int currContext;
    std::string currentOp = "";

    for (char c : data) {

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

            if (context == ENCAPSULATING) {

                // encapsulating operators are hella gay please kill me
                throw "We don't need brackets, right?"; // TODO, obvsly

            } else if (context == LEGAL_ALPHABETICAL) { // This is variables or numbers, handle differently

                if (numbers.count(currentOp.at(0)) > 0) {

                    // This must be a number


                } else {

                    // This must be a variable
                    // TODO

                }

            } else if (context != WHITESPACE) { //Whitespace is literally useless so ignore it

                // This must be an operator
                if (operators.count(currentOp) == 0){
                    throw "Operator not found";
                }
                returnList->push_back(operators.at(currentOp));

            }

            currentOp = c;
        } else {
            currentOp += c; // This char is part of the same "class" so it's part of the same thing
        }

        context = currContext;
    }

    return returnList;
}
