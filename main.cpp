#include <iostream>
#include "code/reqeusters/CinRequester.h"
#include "code/parsers/CinParser.h"
#include "data/datatypes/primitive/PyFunction.h"

int main() {
    CinRequester req;
    CinParser parser;

    Memory& mem = Memory::getInstance();
    std::vector<std::string> code;
    std::vector<std::string> vars;
    vars.emplace_back("input");
    code.emplace_back("print input");
    PyFunction f = PyFunction(code, vars);
    int p = mem.alloc(&f);
    std::string fN{"test"};
    mem.allocPointer(fN, p);

    while (true){
        parser.parseLine(req);
    }

    return 0;
}