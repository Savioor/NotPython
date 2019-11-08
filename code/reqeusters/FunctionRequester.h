//
// Created by alexey on 08/11/2019.
//

#ifndef BASICPYTHONINTERPRETER_FUNCTIONREQUESTER_H
#define BASICPYTHONINTERPRETER_FUNCTIONREQUESTER_H


#include "../IRequester.h"

class FunctionRequester : public IRequester {
    IRequester& subRequester;
    bool finishedRequesting;

public:
    explicit FunctionRequester(IRequester& req);
    virtual std::string* getNext(bool affectEnv) override ;
};


#endif //BASICPYTHONINTERPRETER_FUNCTIONREQUESTER_H
