# cmake minimum version
cmake_minimum_required(VERSION 3.20)
# 项目工程信息
project(cplus_study VERSION 1.0)

# 指定 c++ 版本14 ...
set(CMAKE_CXX_STANDARD 14)

# 构建目标app的源文件
add_executable(cplus_study main.cpp variable/variables.cpp variable/variables.h variable/dataInput.cpp variable/dataInput.h logic-process/logicProcess.cpp logic-process/LogicProcess.h )





