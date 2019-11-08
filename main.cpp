#include "code/reqeusters/CinRequester.h"
#include "code/parsers/CinParser.h"
#include "data/datatypes/primitive/PyFunction.h"
#include "data/datatypes/primitive/PyBoolean.h"

int main() {
    CinRequester req;
    CinParser parser;

    Memory& mem = Memory::getInstance();
    std::vector<std::string> code;
    std::vector<std::string> vars;
    vars.emplace_back("n");

    code.emplace_back("if n == 0");
    code.emplace_back("\treturn 1");
    code.emplace_back("");
    code.emplace_back("return n * fact(n - 1)");

    PyFunction f = PyFunction(code, vars);
    int p = mem.alloc(&f);
    std::string fN{"fact"};
    mem.allocPointer(fN, p);

    while (true){
        parser.parseLine(req);
    }

    return 0;
}