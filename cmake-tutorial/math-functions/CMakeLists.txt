# 添加合适的命令以构建可执行文件MakeTable，并作为构建过程的一部分运行它。需要一些命令去完成这个任务。
add_executable(make-table MakeTable.cpp)
# 增加自定义命令,在运行make-table 如何产生Table.h
# 在编译期间,将会处理这个命令 ...
add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/table.h
        COMMAND make-table ${CMAKE_CURRENT_BINARY_DIR}/table.h
        # 依赖于可执行文件 ..MakeTable ...
        DEPENDS make-table
)


#add_library(math-functions math-func.cpp)
# 为了让math-func.cpp 依赖于其他可以感知到的内容,需要将被依赖内容加入到 源码库中 ..
add_library(math-functions math-func.cpp ${CMAKE_CURRENT_BINARY_DIR}/table.h)

# 导致使用这个库的工程中无法找到当前库的header文件的原因就是,使用了target_link_directories(....),正确应该是使用 target_include_directories ...
# 在我们使用cmake构建工程中所产生的文件的h,那么这个并没有在我们的include 搜索目录中,那么我们需要将它的目录加入,以便能够搜索的例如上面产生的Table.h
# 如果可以,为了方便,我们也可以让它生成到一个特殊的地方 ...
target_include_directories(math-functions INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}  PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
# 库放入lib中
install(TARGETS math-functions DESTINATION lib)
# 头文件放入 include中...
install(FILES math-func.h DESTINATION include)

# 使用 CheckSymbolExists 模块来测试这些函数是否可用 在某些平台（例如Linux）需要链接库m。如果第一次没有找到log和exp，我们需要链接库m并重试

