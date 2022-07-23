# CMake generated Testfile for 
# Source directory: D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial
# Build directory: D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/win-build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[Runs]=] "D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/win-build/cmake-tutorial.exe" "25")
set_tests_properties([=[Runs]=] PROPERTIES  _BACKTRACE_TRIPLES "D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;72;add_test;D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;0;")
add_test([=[Runs-1]=] "D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/win-build/cmake-tutorial.exe" "5")
set_tests_properties([=[Runs-1]=] PROPERTIES  _BACKTRACE_TRIPLES "D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;73;add_test;D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;0;")
add_test([=[Usage]=] "D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/win-build/cmake-tutorial.exe")
set_tests_properties([=[Usage]=] PROPERTIES  PASS_REGULAR_EXPRESSION "Usage:.*number" _BACKTRACE_TRIPLES "D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;75;add_test;D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;0;")
add_test([=[Comp4]=] "D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/win-build/cmake-tutorial.exe" "4")
set_tests_properties([=[Comp4]=] PROPERTIES  PASS_REGULAR_EXPRESSION "4 is 2" _BACKTRACE_TRIPLES "D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;83;add_test;D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;90;do_test;D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;0;")
add_test([=[Comp9]=] "D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/win-build/cmake-tutorial.exe" "9")
set_tests_properties([=[Comp9]=] PROPERTIES  PASS_REGULAR_EXPRESSION "9 is 3" _BACKTRACE_TRIPLES "D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;83;add_test;D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;91;do_test;D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;0;")
add_test([=[Comp5]=] "D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/win-build/cmake-tutorial.exe" "5")
set_tests_properties([=[Comp5]=] PROPERTIES  PASS_REGULAR_EXPRESSION "5 is 2.236" _BACKTRACE_TRIPLES "D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;83;add_test;D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;92;do_test;D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;0;")
add_test([=[Comp7]=] "D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/win-build/cmake-tutorial.exe" "7")
set_tests_properties([=[Comp7]=] PROPERTIES  PASS_REGULAR_EXPRESSION "7 is 2.645" _BACKTRACE_TRIPLES "D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;83;add_test;D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;93;do_test;D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;0;")
add_test([=[Comp25]=] "D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/win-build/cmake-tutorial.exe" "25")
set_tests_properties([=[Comp25]=] PROPERTIES  PASS_REGULAR_EXPRESSION "25 is 5" _BACKTRACE_TRIPLES "D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;83;add_test;D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;94;do_test;D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;0;")
add_test([=[Comp-25]=] "D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/win-build/cmake-tutorial.exe" "-25")
set_tests_properties([=[Comp-25]=] PROPERTIES  PASS_REGULAR_EXPRESSION "-25 is [-nan|nan|0]" _BACKTRACE_TRIPLES "D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;83;add_test;D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;95;do_test;D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;0;")
add_test([=[Comp0.0001]=] "D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/win-build/cmake-tutorial.exe" "0.0001")
set_tests_properties([=[Comp0.0001]=] PROPERTIES  PASS_REGULAR_EXPRESSION "0.0001 is 0.01" _BACKTRACE_TRIPLES "D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;83;add_test;D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;96;do_test;D:/JASONJ-WORKSPACE/cplusplus_study/cmake-tutorial/CMakeLists.txt;0;")
subdirs("math-functions")
