//
// Created by CQSF on 2022/7/21.
//
#include "CalculateSqrtConfig.h"
#include <iostream>
#include <string>
#include <cmath>

#ifdef USE_MATH_FUNC
#include "math-func.h"
#endif

// 仅当定义了这个变量才导入这个header ...
// 使用数学函数 math库已经被废弃 ...

using namespace std;

string printfArgv(char **pString,int length);


double sqrtByStrategy(double value) {
    // 通过宏判断 进行逻辑执行 ....
    #ifdef USE_MATH_FUNC
    {
        // cout << "math func executable" << endl;
        return mySqrtByStrategy(value);
    }
    #else
    {
         // cout << "cmath" << endl;
        return sqrt(value);
    }
    #endif
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        // report version
        std::cout << argv[0] << " Version " << CalculateSqrt_VERSION_MAJOR << "."
                  << CalculateSqrt_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }
    //
    // // 程序输入参数 ...
    // cout << "cmake-tutorial input params " << argc << endl;
    // cout << "cmake-tutorial input argv printf result: \n" << printfArgv(argv,argc) << endl;
    // // 指定c++ 标准,为项目添加一些c++ 特性 ..
    // // double value = std::stod(argv[1]);
    //
    // // 平方根计算
    // cout << "math-func sqrt 4 invoke  result: " << sqrt(4) << endl;
    //
    // double sqrtResult =  sqrtByStrategy(3);
    // double sqrtResult1 = sqrtByStrategy(3);
    // cout << "standard math sqrt 3 invoke result: " << sqrtResult << endl;
    // cout << "standard math sqrt 3 invoke result: " << sqrtResult1 << endl;
    //
    //
    // cout << "2.3 compare to 2.4 result: " << (2.33333333f <= 2.33333333f ? "True" : "False") << endl;
    double value = std::stod(argv[1]);
    // std::cout << value << " is " << sqrtByStrategy(value) << std::endl;
    std::cout << value << " is " << sqrtByFile(value) << std::endl;
}
/**
 * 二维指针处理 ...
 * @param params  二维数组参数
 * @param length 长度
 * @return
 */
string printfArgv(char ** params,int length) {
    string result = "";
    char * temp = NULL;
    if (length > 0) {
        for (int i = 0; i < length; ++i) {
            temp = params[i];
            while(*temp != '\0') {
                result += *temp;
                // 向下移动 ...
                temp ++;
            }

            result += "\n";
        }
    }
    return result;
}


