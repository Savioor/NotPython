//
// Created by alexey on 25/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_ABSTRACTKEYWORD_H
#define BASICPYTHONINTERPRETER_ABSTRACTKEYWORD_H

#include <string>
#include "../../data/Memory.h"
#include "../IRequester.h"

class AbstractKeyword {
protected:
    AbstractKeyword(char *name);

    std::string keyword;

public:
    AbstractKeyword() = delete;
    explicit AbstractKeyword(std::string& name);
    explicit AbstractKeyword(std::string&& name);
    virtual stringIter_t& parse(stringIter_t& ip, stringIter_t& end, IRequester& req) = 0;

    const std::string& getKeyword() const;

    virtual ~AbstractKeyword() = default;
};


#endif //BASICPYTHONINTERPRETER_ABSTRACTKEYWORD_H
