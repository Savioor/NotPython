//
// Created by alexey on 25/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_IREQUESTER_H
#define BASICPYTHONINTERPRETER_IREQUESTER_H


#include <string>
#include <memory>

class IRequester {

public:
    virtual inline std::string* getNext() {
        return getNext(true);
    };
    virtual std::string* getNext(bool affectEnv) = 0;


};


#endif //BASICPYTHONINTERPRETER_IREQUESTER_H
