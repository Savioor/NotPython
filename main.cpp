#include "code/reqeusters/CinRequester.h"
#include "code/parsers/CinParser.h"
#include "data/datatypes/primitive/PyFunction.h"
#include "data/datatypes/primitive/PyBoolean.h"
#include "data/memory-structure/PoolMaster.h"
#include "data/datatypes/primitive/PyString.h"
#include "data/IOR.h"

void testNewMemoryModel(){

    PoolMaster mem;
    objectLoc_t anonPtr = mem.allocateAnon(PyString("Testing"));
    IOR::getInstance().reportOut(((PyPrimitive*)anonPtr.first->safelyRetrieve(anonPtr.second))->asStr());

}

void testParser(){
    CinRequester req;
    CinParser parser;

    Memory& mem = Memory::getInstance();
    std::vector<std::string> code;
    std::vector<std::string> vars;
    vars.emplace_back("n");
//    code.emplace_back("print n");
    code.emplace_back("if n == 0");
    code.emplace_back("\treturn 1");
    code.emplace_back("");
    code.emplace_back("if n == 1");
    code.emplace_back("\treturn 1");
    code.emplace_back("");
    code.emplace_back("return fib(n-1) + fib(n-2)");

    PyFunction f = PyFunction(code, vars);
    int p = mem.alloc(&f);
    std::string fN{"fib"};
    mem.allocPointer(fN, p);

    while (true){
        parser.parseLine(req);
    }
}

int main() {

    testNewMemoryModel();

    return 0;
}
