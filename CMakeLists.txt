cmake_minimum_required(VERSION 3.14)
project(BasicPythonInterpreter)

set(CMAKE_CXX_STANDARD 14)

add_executable(BasicPythonInterpreter main.cpp util/NullPointerException.cpp util/NullPointerException.h parsing/ExpressionParser.cpp parsing/ExpressionParser.h parsing/operators/binary/BinaryOperator.cpp parsing/operators/binary/BinaryOperator.h memory/Class.cpp memory/Class.h parsing/operators/Operator.cpp parsing/operators/Operator.h parsing/operators/Operator.cpp parsing/operators/Operator.h parsing/operators/binary/Addition.cpp parsing/operators/binary/Addition.h memory/MemoryManager.cpp memory/MemoryManager.h)