cmake_minimum_required(VERSION 3.14)
project(BasicPythonInterpreter)

set(CMAKE_CXX_STANDARD 14)

add_executable(BasicPythonInterpreter main.cpp util/NullPointerException.cpp util/NullPointerException.h parsing/ExpressionParser.cpp parsing/ExpressionParser.h parsing/operators/binary/BinaryOperator.cpp parsing/operators/binary/BinaryOperator.h memory/Class.cpp memory/Class.h parsing/operators/Operator.cpp parsing/operators/Operator.h parsing/operators/Operator.cpp parsing/operators/Operator.h memory/MemoryManager.cpp memory/MemoryManager.h memory/builtins/Integer.cpp memory/builtins/Integer.h parsing/operators/ClassOperator.cpp parsing/operators/ClassOperator.h parsing/operators/binary/SimpleBinaryOperator.cpp parsing/operators/binary/SimpleBinaryOperator.h parsing/operators/encapsulating/EncapsulatingOperator.cpp parsing/operators/encapsulating/EncapsulatingOperator.h parsing/operators/encapsulating/Brackets.cpp parsing/operators/encapsulating/Brackets.h)