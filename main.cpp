
#include <iostream>
#include "parsing/ExpressionParser.h"
#include "memory/MemoryManager.h"
#include "memory/builtins/Integer.h"

int main() {

    MemoryManager::getManager().increaseExpDepth();
    ExpressionParser parser = ExpressionParser();
    Class* cls = parser.parse("5** 3 +3 *   5  * 5   ");

    std::cout << ((Integer*)cls)->getValue();

    return 0;
}
