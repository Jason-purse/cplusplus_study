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
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 设置Cmake的一些变量
# set 如果 MINOR 和 MAJOR 一样 那么 MINOR 将会被舍弃 ...
set(CalculateSqrt_VERSION_MAJOR 13)
set(CalculateSqrt_VERSION_MINOR 12)

# 设置链接库可选
# 提供一个选择
option(USE_MATH_FUNC "Use tutorial provided math implementation" ON)

##条件定义
## 使用变量EXTRA_LIBS收集所有可选库，以便之后链接到可执行文件中。类似地，变量EXTRA_INCLUDES表示可选的头文件。这是处理多个可选组件的一种传统方式
if (USE_MATH_FUNC)
    add_subdirectory(math-functions)
    list(APPEND EXTRA_LIBS math-functions)  # 追加一个额外库变量(它本身是列表)
    # 追加一个列表变量 ...
    #list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/math-functions")
endif ()

## 由于我们改写了库的使用需求 ... 上面的条件定义就不再需要了 ...


# configure_file的作用将一份文件拷贝到另一个位置并修改它的内容，使得在代码中使用CMake中定义的变量
# configure_file官方文档：https://cmake.org/cmake/help/latest/command/configure_file.html
# 以下代码的作用就是 创建一个CalculateSqrtConfig.hin 输入文件使用CmakeLists.txt文件中定义的变量) ...
# 此玩意存在构建缓存,所以如果没有生成,那么重新修改文件内容尝试重新生成,一般没有生成是因为比对了文件修改内容进行 重新修改处理的 ....
configure_file(hin/CalculateSqrtConfig.h.in ${PROJECT_SOURCE_DIR}/hout/CalculateSqrtConfig.h)
configure_file(hin/CalculateSqrtConfig.h.in ${PROJECT_BINARY_DIR}/CalculateSqrtConfig.h)

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
#target_include_directories(cmake-tutorial PUBLIC hout ${EXTRA_INCLUDES})
# 当实现了面向库的使用者包含库源目录的情况下,那么上面一行的语句就应该去掉EXTRA_INCLUDES的引用 ... 因为在使用库的时候 已经加入到当前CMAKE源目录中,那么是能够获取到xxxx.h的文件(默认猜测)
target_include_directories(cmake-tutorial PUBLIC ${PROJECT_BINARY_DIR})

# 安装部分 ..
# 它是应用程序部分,需要放入 bin中 ...
install(TARGETS cmake-tutorial DESTINATION bin)
# 头文件依旧放入 include中..
install(FILES ${PROJECT_BINARY_DIR}/CalculateSqrtConfig.h DESTINATION include)


#支持测试
# 增加一个 仪表盘,详情查看后续内容(支持测试使用enable_testing) ...
include(CTest)
# CTest 会自动的调用enable_testing ...
#enable_testing()
# 在这里面的测试参数,我们应该取第二个程序输入参数值 ...  ,第一个是exe入口程序全路径 ... ..(当然同样会传入给我们的main 函数中) ...
add_test(NAME Runs COMMAND cmake-tutorial 25)
add_test(NAME Runs-1 COMMAND cmake-tutorial 5)
# 第一个可执行程序是必传递的 ...
add_test(NAME Usage COMMAND cmake-tutorial)
set_tests_properties(Usage
        # * 表示正则 ... (.*) 匹配0个或者多个字符
        # PASS_REGULAR_EXPRESSION测试属性验证输出是否包含某些字符串。在这个情况下，验证当参数数量错误时是否打印了用法信息。
        PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
        )
# 定义函数,简化测试过程 ...
function(do_test target arg result)
    add_test(NAME Comp${arg} COMMAND ${target} ${arg})
    set_tests_properties(Comp${arg}
            # 此处传递的表达式是希望最后输出的信息是这个 ....
            PROPERTIES PASS_REGULAR_EXPRESSION ${result}
            )
endfunction(do_test)

do_test(cmake-tutorial 4 "4 is 2")
do_test(cmake-tutorial 9 "9 is 3")
do_test(cmake-tutorial 5 "5 is 2.236")
do_test(cmake-tutorial 7 "7 is 2.645")
do_test(cmake-tutorial 25 "25 is 5")
do_test(cmake-tutorial -25 "-25 is [-nan|nan|0]")
do_test(cmake-tutorial 0.0001 "0.0001 is 0.01")

# 重新构建这个程序然后进入构建目录，运行ctest -N和ctest -VV。对于多配置的生成器（例如Visual Studio），必须指定配置类型。
# 例如，要在调试模式下运行测试，在构建目录下使用ctest -C Debug -vv，或者，在IDE中构建RUN_TESTS目标。

#添加系统自省(System Introspection)
#// 检测模块 ...
#// 将在TutorialConfig.h.in中使用新的定义，因此确保在那个文件被配置之前设置它们
include(CheckSymbolExists)
#// 第一个函数名,第二个声明文件, 第三个判断结果 ..变量保存 ...
check_symbol_exists(log "math.h" HAVE_LOG)
check_symbol_exists(exp "math.h" HAVE_EXP)
#// 条件判断使用AND / OR  / XOR ... NOT
if (NOT (HAVE_LOG AND HAVE_EXP))
    #// 如果没有则设置CACHE中的这些变量为UNDEFINED ... 也可以说NULL ...
    unset(HAVE_LOG CACHE)
    unset(HAVE_EXP CACHE)
    #// 设置一个变量保存库名 ... (这将会自动的链接库)
    set(CMAKE_REQUIRED_LIBRARIES "m")
    #// 再次尝试检查 ...
    check_symbol_exists(log "math.h" HAVE_LOG)
    check_symbol_exists(exp "math.h" HAVE_EXP)
    #// 如果有,则将它们加入目标链接库中 ...(参与构建)
    if (HAVE_LOG AND HAVE_EXP)
        #// 这里有所不同,使用PRIVATE,表示这个库独自依赖m 库,将不会暴露出去 ....
        target_link_libraries(math-functions PRIVATE m)
    endif ()
endif ()

#If available, use target_compile_definitions() to specify HAVE_LOG and HAVE_EXP as PRIVATE compile definitions.
# cmake 之前版本 将 这一类的变量需要通过CMAKE 写入到程序中的宏定义,但是现在可以通过编译定义设置 ... 保存这些变量信息 ...
# 所以我们将CalculateSqrtConfig.h.in中的 cmake宏定义注释了 .. 采用这个..
if(HAVE_LOG AND HAVE_EXP)
    # 然后将这些值添加到PRIVATE编译器定义 ...
    target_compile_definitions(math-functions
            PRIVATE "HAVE_LOG" "HAVE_EXP")
endif()

# 指定编译器定义

# 7.构建安装程序 ..
#假定我们想将我们的项目发布给其他人。我们希望提供在多种平台上的二进制文件和源代码。
#这和我们在第4步讲的安装有一些不同，在第4步中我们只是安装了从源代码构建的二进制文件
#我们将构建一个安装包，它支持二进制安装和包管理特性 我们将使用CPack去创建特定于平台的安装程序

# This module will include any runtime libraries that are needed by the project for the current platform
include(InstallRequiredSystemLibraries)
# 设置文件版权说明 ...
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
# 设置一些CPACK 变量,CPack能够利用这些变量 以及  这个构建系统中的其他一些属性来构建安装器 ...
set(CPACK_PACKAGE_VERSION_MAJOR "${CalculateSqrt_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${CalculateSqrt_VERSION_MINOR}")
include(CPack)
# 接下来以正常的方式构建这个项目，然后运行cpack。要构建一个二进制版本，在binary目录(build文件夹内)运行：
# cpack
# 使用-G选项指定生成器(特定的生成器 生成特定的打包程序)。对于多配置构建（例如Visual Studio），使用-C选项指定配置(打包版本 / 调试  / 发行 ..)。例如
# cpack -G ZIP -C Debug
# 要创建一个源代码版本，输入：
# cpack --config CPackSourceConfig.cmake

# 然后在这个构建系统中,构建你想要的打包文件 ..
#https://juejin.cn/post/6844904015587704839#heading-25
# 在window上我们安装的cmake ,并不是GNU 形式的 工具,它是nmake,这就让我有点头大 ..
# 所以在windows上开发是真的恶心 .... cmake -G "Unix Makefiles" ../
# 所以我创建了一个win-build 目录用于构建一个新的构建系统,然后由于clion中我没有找到如何 cpack 打包 ... 所以直接用命令行形式直接处理 ..
# 最好使用MinGW GUI / BaSH 进行命令执行,否则windows上命令完全不允许你这样做 ...
# 其次由于cpack 打包需要对应的生成器,那么我们仅仅使用最广泛的形式,例如zip ,那么直接打包查看效果即可 ...

# 仪表盘支持
# 首先关闭 enable_testing ..
# 开启仪表盘支持 ..
# 将这个放到前面
#include(CTest)
# CTest模块将自动调用enable_testing()，所以我们可以从CMake文件中移除它。