//
// Created by CQSF on 2022/7/21.
//
#include <iostream>

double sqrt(int x) {
    // result = (x / 2 + x) / 2 , 判断 result == next(result)
    double firstValue = 1;
    double check = 0.00001;
    do {
        firstValue = (x / firstValue + firstValue) / 2;

        // 浮点数不能够直接比较(好像在c语言中是,在c++中好像比较也没有什么大的问题 ...) ...
        double checkValue = firstValue * firstValue - x;

        // 根据算出来的值进行判断 ...
        if ((checkValue > 0 ? checkValue : -checkValue) <= check) {
            return firstValue;
        }
    }while(true);
}

