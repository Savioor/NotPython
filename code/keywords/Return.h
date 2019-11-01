//
// Created by alexey on 01/11/2019.
//

#ifndef BASICPYTHONINTERPRETER_RETURN_H
#define BASICPYTHONINTERPRETER_RETURN_H


#include "AbstractKeyword.h"
#include "../../data/datatypes/primitive/PyFunction.h"

class Return : public AbstractKeyword {
public:
    Return();
    virtual ~Return() = default;

    stringIter_t &parse(stringIter_t &ip, stringIter_t &end, IRequester& req) override;
};


#endif //BASICPYTHONINTERPRETER_RETURN_H
