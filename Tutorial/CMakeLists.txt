cmake_minimum_required(VERSION 3.20)
project(Tutorial VERSION 1.0)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED  True)
option(USE_MATH_FUNC "Use tutorial provided math implementation" ON)
if(USE_MATH_FUNC)
    add_subdirectory(math-functions)
    list(APPEND EXTRA_LIBS math-functions)  # 追加一个额外库变量(它本身是列表)
endif()
configure_file(Tutorial.h.in Tutorial.h)
add_executable(Tutorial main.cpp)

target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})
target_include_directories(Tutorial PUBLIC ${PROJECT_BINARY_DIR})

#install(TARGETS cmake-tutorial DESTINATION bin)
#install(FILES "${PROJECT_SOURCE_DIR}/hout/CalculateSqrtConfig.h" DESTINATION include)
#

## 添加测试
#enable_testing()
#add_test(NAME Runs COMMAND cmake-tutorial 25)
## 是否能打印程序的使用方式
#add_test(NAME Usage COMMAND cmake-tutorial)
#set_tests_properties(Usage PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number")
#
#
## 定义一个函数来简化添加测试用例的过程
#function(do_test target arg result)
#    add_test(NAME Comp${arg} COMMAND ${target} ${arg})
#    set_tests_properties(Comp${arg} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
#endfunction(do_test)
#
## 一些基于结果的测试
#do_test(cmake-tutorial 4 "4 is 2")
#do_test(cmake-tutorial 9 "9 is 3")
#do_test(cmake-tutorial 5 "5 is 2.236")
#do_test(cmake-tutorial 7 "7 is 2.645")
#do_test(cmake-tutorial 25 "25 is 5")
#do_test(cmake-tutorial -25 "-25 is [-nan|nan|0]")
#do_test(cmake-tutorial 0.0001 "0.0001 is 0.01")