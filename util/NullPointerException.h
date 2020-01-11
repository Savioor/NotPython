//
// Created by alexey on 24/11/2019.
//

#ifndef BASICPYTHONINTERPRETER_NULLPOINTEREXCEPTION_H
#define BASICPYTHONINTERPRETER_NULLPOINTEREXCEPTION_H

#include <stdexcept>

class NullPointerException : public std::runtime_error {

public:
    NullPointerException();

};


#endif //BASICPYTHONINTERPRETER_NULLPOINTEREXCEPTION_H
