//
// Created by alexey on 26/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_PRINT_H
#define BASICPYTHONINTERPRETER_PRINT_H


#include "../AbstractKeyword.h"

class Print : public AbstractKeyword {
public:
    Print();
    virtual stringIter_t &parse(stringIter_t &ip, stringIter_t &end) override;
};


#endif //BASICPYTHONINTERPRETER_PRINT_H
