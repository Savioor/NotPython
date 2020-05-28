
#include <iostream>
#include "memory/builtins/primitive/PyString.h"
#include "parsing/ExpressionParser.h"
#include "memory/MemoryManager.h"
#include "memory/builtins/primitive/PyInteger.h"
#include "memory/builtins/PyVariable.h"

int main() {

    ExpressionParser& parser = ExpressionParser::getParser();
    MemoryManager& manager = MemoryManager::getManager(); // for debug

//    std::string s{"nigga"};
//    auto* var = new PyVariable(s);
//    var->setChild(new PyInteger(5));
    while (1) {
        PyClass *cls = parser.parseNewExpression(std::cin);
    };

    return 0;
}
