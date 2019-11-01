//
// Created by alexey on 30/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_FUNCTIONPARSER_H
#define BASICPYTHONINTERPRETER_FUNCTIONPARSER_H


#include "GenericParser.h"

class FunctionParser : public GenericParser {
public:
    FunctionParser();

    virtual ~FunctionParser() = default;
};


#endif //BASICPYTHONINTERPRETER_FUNCTIONPARSER_H
