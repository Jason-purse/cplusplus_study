# 请先阅读 README.MD 文档 ...
# 这个作为CMakeLists.txt 的第一行...
# 设置cmake 最小版本
cmake_minimum_required(VERSION 3.20)
# 设置项目的名称 和 版本
project(cmake-tutorial VERSION 1.0)

# 指定 c++ 版本14 ...
# 它们必须放置在 add_executable之上 ...
# 同时还可以指定 必须 = True ..
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED  True)

# 设置Cmake的一些变量
# set 如果 MINOR 和 MAJOR 一样 那么 MINOR 将会被舍弃 ...
set(CalculateSqrt_VERSION_MAJOR 13)
set(CalculateSqrt_VERSION_MINOR 12)

# 设置链接库可选
# 提供一个选择
#option(USE_MATH_FUNC "Use tutorial provided math implementation" ON)

#条件定义
# 使用变量EXTRA_LIBS收集所有可选库，以便之后链接到可执行文件中。类似地，变量EXTRA_INCLUDES表示可选的头文件。这是处理多个可选组件的一种传统方式
if(USE_MATH_FUNC)
    add_subdirectory(math-functions)
    # 追加一个额外库变量(它本身是列表)
    list(APPEND EXTRA_LIBS math-functions)
    # 追加一个列表变量 ...
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/math-functions")
endif()


# configure_file的作用将一份文件拷贝到另一个位置并修改它的内容，使得在代码中使用CMake中定义的变量
# configure_file官方文档：https://cmake.org/cmake/help/latest/command/configure_file.html
# 以下代码的作用就是 创建一个CalculateSqrtConfig.hin 输入文件使用CmakeLists.txt文件中定义的变量) ...
# 此玩意存在构建缓存,所以如果没有生成,那么重新修改文件内容尝试重新生成,一般没有生成是因为比对了文件修改内容进行 重新修改处理的 ....
configure_file(hin/CalculateSqrtConfig.h.in ${PROJECT_SOURCE_DIR}/hout/CalculateSqrtConfig.h)


# 指定项目编译的时候需要include 的文件路径 ... PROJECT_BINARY_DIR 变量为编译发生的目录 (make 执行的目录).... PROJECT_SOURCE_DIR 表示工程所在目录
# 也就是 target_include_directories(....files, "${PROJECT_BINARY_DIR}") ....

add_executable(cmake-tutorial main.cpp)


#add_subdirectory(math-functions)
#target_link_libraries(cmake-tutorial PUBLIC  math-functions)
# 增加了额外的可选链接库配置时,那么我们应该根据变量来链接目标库
target_link_libraries(cmake-tutorial PUBLIC ${EXTRA_LIBS})

# include 搜索目录语句应该放在此配置文件末尾 ...
# 这里将hout 纳入 #include 文件搜索目录
#target_include_directories(cmake-tutorial PUBLIC hout  math-functions)
# 同样这里就应该变成
target_include_directories(cmake-tutorial PUBLIC hout ${EXTRA_INCLUDES})