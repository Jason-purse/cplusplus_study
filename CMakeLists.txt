cmake_minimum_required(VERSION 3.20)
project(cplus_study)

set(CMAKE_CXX_STANDARD 14)

add_executable(cplus_study main.cpp variable/variables.cpp variable/variables.h variable/dataInput.cpp variable/dataInput.h logic-process/logicProcess.cpp logic-process/LogicProcess.h)
