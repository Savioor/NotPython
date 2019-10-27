//
// Created by alexey on 24/10/2019.
//

#include "PyString.h"

PyString::PyString() : PyObject("string") {

}

PyString::PyString(char *str) : PyObject("string"), myValue(str) {

}

PyString::PyString(std::string &str) : PyObject("string"), myValue(str) {

}

PyString::PyString(std::string && inp) : PyObject("string"), myValue(inp){
}