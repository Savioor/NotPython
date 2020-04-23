cmake_minimum_required(VERSION 3.14)
project(BasicPythonInterpreter)

set(CMAKE_CXX_STANDARD 14)

add_executable(BasicPythonInterpreter main.cpp util/NullPointerException.cpp util/NullPointerException.h parsing/ExpressionParser.cpp parsing/ExpressionParser.h parsing/operators/binary/BinaryExpression.cpp parsing/operators/binary/BinaryExpression.h memory/Class.cpp memory/Class.h)