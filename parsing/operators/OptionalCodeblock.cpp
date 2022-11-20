//
// Created by USER on 6/5/2020.
//

#include "OptionalCodeblock.h"

#include <utility>
#include "../../memory/MemoryManager.h"
#include "../../memory/builtins/primitive/PyBool.h"

PyClass *OptionalCodeblock::getAsClass() const {

    if (parentBlock != nullptr) {
        PyClass *parentResponse;
        parentResponse = parentBlock->getAsClass();
        if (parentResponse != nullptr) {
            return parentResponse;
        }
    }

    if (condition != nullptr) {
        PyClass& condAnsr = condition->getAsClass()->getRaw();
        if (condAnsr.type != pyBOOL) {
            throw std::runtime_error("Conditional codeblock expected boolean");
        }
        if (((PyBool&)condAnsr).getValue()) {
            return codeblock->execute();
        }
    } else {
        return codeblock->execute();
    }

    if (hasChild) return nullptr;

    return MemoryManager::getManager().getNone();

}

OptionalCodeblock::OptionalCodeblock(PyCodeblock* c, std::shared_ptr<OptionalCodeblock> oc, std::shared_ptr<RoundBrackets> cond)
    : codeblock{c}, parentBlock{std::move(oc)}, condition{std::move(cond)}, hasChild{false}, Operator(OPTIONAL_CODEBLOCK) {
    if (parentBlock != nullptr) parentBlock->hasChild = true;
}
