//
// Created by alexey on 09/11/2019.
//

#ifndef BASICPYTHONINTERPRETER_DEBUG_H
#define BASICPYTHONINTERPRETER_DEBUG_H

#define DEBUG true

#if DEBUG

#define MEM_DEBUG true
#define OBJECT_DEBUG false
#define KEYWORD_DEBUG true
#define FUNCTION_CALL_DEBUG false
#define FUNCTION_RETURN_DEBUG true
#define ASSIGN_DEBUG true


#define POOL_DEBUG true
#if POOL_DEBUG
#define ALLOC_HERE_DEBUG true
#define FREE_DEBUG true
#endif

#endif

#endif //BASICPYTHONINTERPRETER_DEBUG_H
