
#include <iostream>
#include "parsing/ExpressionParser.h"
#include "memory/MemoryManager.h"

int main() {

    MemoryManager::getManager().increaseExpDepth();
    ExpressionParser parser = ExpressionParser();
    auto lis = *parser.toOperatorList("1 + 1");

    for (auto i : lis){
        std::cout << "bruh\n";
    }

    return 0;
}
