# Cmake 工程
以下的MathFunctions 指的是当前math-functions工程
## 基础知识
- CMake支持大写、小写或大小写混合命令
- CMakeCache.txt所在的目录，即build目录
- Cmake 中可以手动包含扫描include 文件的目录 ...
- PROJECT_BINARY_DIR 就是构建目录 

  target_include_directories(cmake-tutorial PUBLIC "${PROJECT_BINARY_DIR}")
## 构建工程
- 构建一个"build"目录(我们称为MakeLists.txt叫做构建目录,但是我们一般会创建一个额外的目录来保存cmake执行所产生的编译系统)
    ```shell
      cd build && cmake ../
    ```
- 使用产生的构建系统编译、链接该项目
    ```shell
      cmake --build .
    ```
- 这将产生一个可执行文件,直接调用即可...

## 为项目增加一个本地库
- 首先让一个库CMakeLists.txt包含add_library( .... )
  ```shell
    add_library(math-functions math-func.cpp)
  ```
- 包含这个目录,让它参与构建
  ```shell
    add_subdirectory(MathFunctions)
  ```
- 包含一个目标链接库设置
  ```shell
    target_link_libraries(Tutorial PUBLIC MathFunctions)
  ```
- 将库设定到包含include 文件搜索路径,例如加入了一个MathFunctions目录能够搜索header文件
  ```shell
    arget_include_directories(Tutorial PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/MathFunctions"
                          )
  ```
## 设置库可选
  需要设置选项Option ...
  ```shell
    更新USE_MYMATH的值。最简单的方式是使用 cmake-gui 或 ccmake ，如果你在终端中的话。或者，如果你想通过命令行更改选项的话，你可以：
    if(USE_MYMATH)
      add_subdirectory(MathFunctions)
      list(APPEND EXTRA_LIBS MathFunctions)
      list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
    endif()
    // 将他们加入到链接库列表中 ...
    target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})
    // 同样加入EXTRA_INCLUDES 变量中的值作为include
    target_include_directories(Tutorial PUBLIC
                               "${PROJECT_BINARY_DIR}"
                               ${EXTRA_INCLUDES}
                               )
                            
  ```
  然后可选导入头文件
  ```shell
    #ifdef USE_MYMATH
    #include "MathFunctions.h"
    #endif
  ```
同样条件执行代码
```shell
#ifdef USE_MYMATH
  const double outputValue = mysqrt(inputValue);
#else
  const double outputValue = sqrt(inputValue);
#endif
```
最后如果是命令行,通过命令设置选项条件是否定义
```shell
 cmake ../ -DUSE_MYMATH=OFF
```
因为我们本来是需要在这个hin目录下的CalculateSqrtConfig.h.in中定义一个 #cmakedefine USE_MYMATH
cmake 会自动处理
在前面我们通过configure_file 进行cmake 模板文件翻译 .. 可以使用一些cmake 变量 ...
在IDE中,可以直接取消这个选项的定义即可 ...(注释)

# 为库添加使用需求
```text
target_compile_definitions()
target_compile_options()
target_include_directories()
target_link_libraries()
```
以上命令可以使用来增加库的使用需求 ..
首先声明任何链接到MathFunctions的人都需要包含当前的源目录，而MathFunctions本身不需要。所以这可以成为一个INTERFACE使用需求。（相关内容请参考CMake构建系统https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html）
记住，INTERFACE意味着库的使用者需要，但库的设计者不需要。添加下面这行到MathFunctions/CMakeLists.txt文件尾：
```text
target_include_directories(MathFunctions
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )
```
那么在使用库中的工程中就不再需要条件包含EXTRA_INCLUDES变量的使用 删除它 
```text
if(USE_MYMATH)
  add_subdirectory(MathFunctions)
  list(APPEND EXTRA_LIBS MathFunctions)
endif()
```
并修改include 包含目录配置,也不再需要 INCLUDE 变量 ...
```text
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
```
## 安装(installing) 以及 测试(testing)
### 安装规则(Install Rules)
安装规则相当简单：对于MathFunctions，我们想安装库和头文件；对于应用程序，我们想安装可执行文件和配置后的头文件。
所以在MathFunctions/CMakeLists.txt文件的末尾添加：
```text
install(TARGETS MathFunctions DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)
```
在命令行中使用cmake 命令的安装选项（CMake 3.15中引入，旧版的CMake必须使用make install等本地的构建命令）。对于多配置的工具，不要忘了使用--config参数时指定配置。如果使用一个IDE，你只需要构建INSTALL这个目标。这将安装合适的头文件、库和可执行文件。例如：
默认情况下，需要以管理员身份运行，否则可能会权限不足。
```text
cmake --install .
```
CMake变量CMAKE_INSTALL_PREFIX用于决定这些文件被安装到哪里，它是一个安装前缀，即一个目录
使用cmake --install命令，可以通过--prefix参数重写安装前缀
```text
cmake --install . --prefix "/home/myuser/installdir"
```
### 测试支持(Testing Support)
