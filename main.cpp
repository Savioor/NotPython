
#include <iostream>
#include "parsing/ExpressionParser.h"
#include "memory/MemoryManager.h"
#include "memory/builtins/Integer.h"

int main() {

    MemoryManager::getManager().increaseExpDepth();
    ExpressionParser parser = ExpressionParser();
    Class* cls = parser.parse("51 + 1 51");

    std::cout << ((Integer*)cls)->getValue();

    return 0;
}
