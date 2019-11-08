//
// Created by alexey on 30/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_VECTORREQUESTER_H
#define BASICPYTHONINTERPRETER_VECTORREQUESTER_H


#include <vector>
#include "../IRequester.h"

class VectorRequester : public IRequester {

protected:
    std::vector<std::string>& data;
    int lastInd = 0;

public:
    VectorRequester(std::vector<std::string>& v);

    virtual std::string* getNext(bool affectEnv) override ;

};


#endif //BASICPYTHONINTERPRETER_VECTORREQUESTER_H
