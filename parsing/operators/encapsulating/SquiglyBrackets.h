//
// Created by alexey on 26/05/2020.
//

#ifndef BASICPYTHONINTERPRETER_SQUIGLYBRACKETS_H
#define BASICPYTHONINTERPRETER_SQUIGLYBRACKETS_H


#include "EncapsulatingOperator.h"

class SquiglyBrackets : public EncapsulatingOperator {

public:
    SquiglyBrackets();

    EncapsulatingOperator *supplySelf() override;

    void supplyInnards(std::string *innards) override;

    bool atEncapsulationEnd(char currChar) override;

    PyClass *getAsClass() const override;

protected:
    std::string* expr;
    int bracketDepthCount;
    char lastChar;
    bool inString;
    bool isDoubleQuoteString;
    PyClass* asCodeBlock;


};


#endif //BASICPYTHONINTERPRETER_SQUIGLYBRACKETS_H
