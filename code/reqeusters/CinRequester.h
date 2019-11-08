//
// Created by alexey on 27/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_CINREQUESTER_H
#define BASICPYTHONINTERPRETER_CINREQUESTER_H


#include "../IRequester.h"

class CinRequester : public IRequester {

public:
    virtual std::string* getNext(bool affectEnv) override ;


};


#endif //BASICPYTHONINTERPRETER_CINREQUESTER_H
