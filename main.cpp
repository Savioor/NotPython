
#include <iostream>
#include <fstream>
#include "memory/builtins/primitive/PyString.h"
#include "parsing/ExpressionParser.h"
#include "memory/MemoryManager.h"
#include "memory/builtins/primitive/PyInteger.h"
#include "memory/builtins/PyVariable.h"

void run_from_file(std::string&& filePath) {

    std::ifstream ss;
    ExpressionParser& parser = ExpressionParser::getParser();
    ss.open(filePath, std::ifstream::in);

    while (!ss.eof()){
        char peek = ss.peek();
        if (peek == ' ' || peek == '\r' || peek == '\n' || peek == '\t'){
            ss.get();
            continue;
        }
        parser.parseNewExpression(ss);
    }

}


int main() {

    ExpressionParser& parser = ExpressionParser::getParser();
    MemoryManager& manager = MemoryManager::getManager(); // for debug

//    while (1) {
//        PyClass *cls = parser.parseNewExpression(std::cin);
//    };

//    run_from_file("C:\\Users\\USER\\CLionProjects\\NotPython\\examples\\find_primes.npy");
    run_from_file("/media/alexey/hdd/code/NotPython/examples/inheritance.npy");
//    run_from_file("C:\\Users\\USER\\CLionProjects\\NotPython\\examples\\prng.npy");

    return 0;
}

