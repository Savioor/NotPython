//
// Created by USER on 5/13/2020.
//

#ifndef BASICPYTHONINTERPRETER_STRINGLITERAL_H
#define BASICPYTHONINTERPRETER_STRINGLITERAL_H


#include "EncapsulatingOperator.h"

class StringLiteral : public EncapsulatingOperator {

public:
    StringLiteral(bool);

    EncapsulatingOperator *supplySelf() override;

    void supplyInnards(std::string *innards) override;

    bool atEncapsulationEnd(char currChar) override;

    PyClass *getAsClass() const override;

private:
    char lastChar;
    bool isDoubleQuote;
    std::string* value;

};


#endif //BASICPYTHONINTERPRETER_STRINGLITERAL_H
