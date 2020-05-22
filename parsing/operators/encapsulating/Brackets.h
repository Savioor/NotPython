//
// Created by USER on 5/8/2020.
//

#ifndef BASICPYTHONINTERPRETER_BRACKETS_H
#define BASICPYTHONINTERPRETER_BRACKETS_H


#include "EncapsulatingOperator.h"

class Brackets : public EncapsulatingOperator {

public:
    Brackets(char, char);

    void supplyInnards(std::string *innards) override;

    bool atEncapsulationEnd(char currChar) override;

    PyClass *getAsClass() const override = 0;

protected:
    std::string* expr;
    int bracketDepthCount;
    char lastChar;
    bool inString;
    bool isDoubleQuoteString;

    char openingChar;
    char closingChar;

};


#endif //BASICPYTHONINTERPRETER_BRACKETS_H
