//
// Created by alexey on 04/11/2019.
//

#ifndef BASICPYTHONINTERPRETER_BLOCKREQUESTER_H
#define BASICPYTHONINTERPRETER_BLOCKREQUESTER_H


#include "../IRequester.h"

class BlockRequester : public IRequester {

    IRequester& subRequester;

public:
    BlockRequester(IRequester& req);
    virtual std::string* getNext();


};


#endif //BASICPYTHONINTERPRETER_BLOCKREQUESTER_H
