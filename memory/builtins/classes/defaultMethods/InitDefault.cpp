//
// Created by alexey on 11/20/22.
//

#include "InitDefault.h"
PyClass* InitDefault::process(std::map<std::string, PyClass*>& map)
{
	return map["self"];
}

InitDefault::InitDefault(PyClass* vl) : PyInternalFunction(vl)
{

}
