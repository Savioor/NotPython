//
// Created by USER on 6/5/2020.
//

#ifndef BASICPYTHONINTERPRETER_OPTIONALCODEBLOCK_H
#define BASICPYTHONINTERPRETER_OPTIONALCODEBLOCK_H


#include <memory>
#include "Operator.h"
#include "../../memory/builtins/PyCodeblock.h"
#include "encapsulating/RoundBrackets.h"

class OptionalCodeblock : public Operator {

public:
    OptionalCodeblock(PyCodeblock* , std::shared_ptr<OptionalCodeblock>, std::shared_ptr<RoundBrackets>);

    PyClass *getAsClass() const override;



private:

    PyCodeblock* codeblock;
    std::shared_ptr<OptionalCodeblock> parentBlock;
    std::shared_ptr<RoundBrackets> condition;
    bool hasChild;

};


#endif //BASICPYTHONINTERPRETER_OPTIONALCODEBLOCK_H
