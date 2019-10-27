//
// Created by alexey on 25/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_IREQUESTER_H
#define BASICPYTHONINTERPRETER_IREQUESTER_H


#include <string>
#include <memory>

class IRequester {

public:
    virtual std::string* getNext() = 0;

};


#endif //BASICPYTHONINTERPRETER_IREQUESTER_H
