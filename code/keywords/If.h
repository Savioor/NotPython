//
// Created by alexey on 03/11/2019.
//

#ifndef BASICPYTHONINTERPRETER_IF_H
#define BASICPYTHONINTERPRETER_IF_H


#include "AbstractKeyword.h"

class If : public AbstractKeyword {
public:
    virtual ~If() = default;
    If();

    stringIter_t &parse(stringIter_t &ip, stringIter_t &end, IRequester& req) override;
};


#endif //BASICPYTHONINTERPRETER_IF_H
