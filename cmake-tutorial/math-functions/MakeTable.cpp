//
// Created by CQSF on 2022/7/22.
//
/**
 * 保留了一个张计算了平方差的表 ...
 */
// A simple program that builds a sqrt table
#include <cmath>
#include <fstream>
#include <iostream>
/**
 * 根据传递的文件名 进行处理 ... 输出到文件中 ...
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char* argv[])
{
    // make sure we have enough arguments
    if (argc < 2) {
        return 1;
    }
    std::cout << "invoke sqrt table progress" << std::endl;
    // 打开一个文件流(模式, 输出) ..
    // 具体后续学习api ...
    std::ofstream fout(argv[1], std::ios_base::out);
    const bool fileOpen = fout.is_open();
    if (fileOpen) {
        fout << "double sqrtTable[] = {" << std::endl;
        for (int i = 0; i < 10; ++i) {
            // 静态强转 ...
            fout << sqrt(static_cast<double>(i)) << "," << std::endl;
        }
        // close the table with a zero
        fout << "0};" << std::endl;
        fout.close();
    }
    return fileOpen ? 0 : 1; // return 0 if wrote the file
}

