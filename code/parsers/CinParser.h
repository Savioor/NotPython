//
// Created by alexey on 30/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_CINPARSER_H
#define BASICPYTHONINTERPRETER_CINPARSER_H


#include "GenericParser.h"

class CinParser : public GenericParser {
public:
    CinParser() = default;

    virtual bool parseLine(IRequester&) override;
};


#endif //BASICPYTHONINTERPRETER_CINPARSER_H
