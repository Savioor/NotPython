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
    vars.emplace_back("inp1");
    vars.emplace_back("inp2");
    code.emplace_back("return inp1 + inp2");
    PyFunction f = PyFunction(code, vars);
    int p = mem.alloc(&f);
    std::string fN{"test"};
    mem.allocPointer(fN, p);

    while (true){
        parser.parseLine(req);
    }

    return 0;
}