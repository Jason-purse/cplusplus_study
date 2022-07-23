//
// Created by CQSF on 2022/7/22.
//

#include "math-func.h"
#include <iostream>
#include <cmath>
#include "table.h"

using namespace std;

double sqrt(double value) {
    if (value <= 0) {
        return 0;
    }
    double initValue = 1;
    double precision = 0.00001;
    double tempValue = 0;
    do {
        initValue = (value / initValue + initValue) / 2;
        tempValue = initValue * initValue - value;
    } while ((tempValue > 0 ? tempValue : -tempValue) > precision);

    return initValue;
}

/**
 * 这个函数 针对系统检测 ... 所产生的一个函数,对HAVE_LOG .. 等等做出判断 ..
 * 它取决于其他工程使用这个库时需要为这个库 提供编译选项( 详情可以查看 目标工程的CMakeLists.txt中 针对这个库的compilerOptions配置) ...
 * @param value
 * @return
 */
double mySqrtByStrategy(double value) {
    // 可以这样判断定义的宏变量 ...
    #if defined(HAVE_LOG) && defined(HAVE_EXP)
        // if 语句是可以花括号的 ...
        // 这里假设 使用 std: exp / log 防止报错 ..
        double result = exp(log(value) * 0.5);
        std::cout << "Computing sqrt of " << value << " to be " << result << " using log and exp" << std::endl;
        return result;
    #else
        return sqrt(value);
    #endif
}

/**
 * 此库默认依赖的一些配置 所支撑的一些函数设定测试 ...
 * @param x
 * @return
 */
double sqrtByFile(double x) {
    if (x <= 0) {
        return 0;
    }

    // 使用表来帮助找到一个初始值
    double result = x;
    if (x >= 1 && x < 10) {
        std::cout << "Use the table to help find an initial value " << std::endl;
        result = sqrtTable[static_cast<int>(x)];
        return result;
    }

    // 进行10次迭代
    for (int i = 0; i < 10; ++i) {
        if (result <= 0) {
            result = 0.1;
        }
        double delta = x - (result * result);
        result = result + 0.5 * delta / result;
        std::cout << "Computing sqrt of " << x << " to be " << result << std::endl;
    }

    return result;

}