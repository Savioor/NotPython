//
// Created by USER on 5/8/2020.
//

#ifndef BASICPYTHONINTERPRETER_ENCAPSULATINGOPERATOR_H
#define BASICPYTHONINTERPRETER_ENCAPSULATINGOPERATOR_H

#include <string>
#include "../../../memory/Class.h"
#include "../Operator.h"

class EncapsulatingOperator : public Operator {

public:
    virtual ~EncapsulatingOperator() = default;
    EncapsulatingOperator();

    virtual EncapsulatingOperator* supplySelf() = 0;
    virtual void supplyInnards(std::string* innards) = 0;
    virtual bool atEncapsulationEnd(char currChar) = 0;

    static bool isInsideString(bool wasInsideLastChar, bool isDoubleQuote, char lastChar, char thisChar);

};


#endif //BASICPYTHONINTERPRETER_ENCAPSULATINGOPERATOR_H
