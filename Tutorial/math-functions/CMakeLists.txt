add_library(math-functions math-func.cpp)
target_include_directories(math-functions
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
        )