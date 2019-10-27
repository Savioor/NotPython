//
// Created by alexey on 25/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_GENERICPARSER_H
#define BASICPYTHONINTERPRETER_GENERICPARSER_H


#include <vector>
#include "IRequester.h"
#include "keywords/AbstractKeyword.h"

class GenericParser {
protected:
    std::vector<AbstractKeyword*> keywords;

public:
    GenericParser();

    virtual void parseLine(IRequester&);
};


#endif //BASICPYTHONINTERPRETER_GENERICPARSER_H
