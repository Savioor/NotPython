//
// Created by USER on 5/8/2020.
//

#ifndef BASICPYTHONINTERPRETER_ENCAPSULATINGOPERATOR_H
#define BASICPYTHONINTERPRETER_ENCAPSULATINGOPERATOR_H

#include <string>
#include "../../../memory/Class.h"

class EncapsulatingOperator {

public:
    virtual ~EncapsulatingOperator();
    EncapsulatingOperator(char, char, bool, std::string*);

    const char openingChr;
    const char closingChr;
    const bool allowNesting;
    const std::string* data;

    virtual Class* consume() = 0;

};


#endif //BASICPYTHONINTERPRETER_ENCAPSULATINGOPERATOR_H
