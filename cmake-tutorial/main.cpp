//
// Created by CQSF on 2022/7/21.
//
#include "CalculateSqrtConfig.h"
#include <iostream>
// 仅当定义了这个变量才导入这个header ...
#ifdef USE_MATH_FUNC
#include "math-func.h"
#endif
// 使用数学函数 math库已经被废弃 ...
#include <cmath>


using namespace std;

double sqrtByStrategy(double value) {
    // 通过宏判断 进行逻辑执行 ....
    #ifdef USE_MATH_FUNC
    {
        cout << "math func executable" << endl;
        return sqrt((int)value);
    }
    #else
    {
         cout << "cmath" << endl;
        return sqrt(value);
    }
    #endif
}

int main(int argc, char *argv[]) {
    cout << "value CalculateSqrt_VERSION_MAJOR = " << CalculateSqrt_VERSION_MAJOR << endl;
    cout << "value CalculateSqrt_VERSION_MINOR = " << CalculateSqrt_VERSION_MINOR << endl;

    // 指定c++ 标准,为项目添加一些c++ 特性 ..
    // double value = std::stod(argv[1]);

    // 平方根计算
    cout << "math-func sqrt 4 invoke  result: " << sqrt(4) << endl;

    double sqrtResult =  sqrtByStrategy(3);
    double sqrtResult1 = sqrtByStrategy(3);
    cout << "standard math sqrt 3 invoke result: " << sqrtResult << endl;
    cout << "standard math sqrt 3 invoke result: " << sqrtResult1 << endl;


    cout << "2.3 compare to 2.4 result: " << (2.33333333f <= 2.33333333f ? "True" : "False") << endl;

}


