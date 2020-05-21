
#include <iostream>
#include "memory/builtins/PyString.h"
#include "parsing/ExpressionParser.h"
#include "memory/MemoryManager.h"
#include "memory/builtins/PyInteger.h"
#include "memory/builtins/PyVariable.h"

int main() {

    ExpressionParser parser = ExpressionParser();

//    std::string s{"nigga"};
//    auto* var = new PyVariable(s);
//    var->setChild(new PyInteger(5));
    while (1) {
        MemoryManager::getManager().increaseExpDepth();
        PyClass *cls = parser.parse(std::cin);
        std::cout << cls->asString()->getValue() << std::endl;
        MemoryManager::getManager().decreaseExpDepth();
    };

    return 0;
}
