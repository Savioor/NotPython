//
// Created by alexey on 11/20/22.
//

#ifndef BASICPYTHONINTERPRETER_MEMORY_BUILTINS_CLASSES_DEFAULTMETHODS_INITDEFAULT_H
#define BASICPYTHONINTERPRETER_MEMORY_BUILTINS_CLASSES_DEFAULTMETHODS_INITDEFAULT_H

#include "../../functions/PyInternalFunction.h"
class InitDefault : public PyInternalFunction
{

public:
	InitDefault(PyClass*);

protected:
	PyClass *process(std::map<std::string, PyClass *> &map) override;

};

#endif //BASICPYTHONINTERPRETER_MEMORY_BUILTINS_CLASSES_DEFAULTMETHODS_INITDEFAULT_H
