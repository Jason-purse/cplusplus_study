# Cmake 工程
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
