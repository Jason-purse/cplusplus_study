//
// Created by Smile Boy on 2022/7/20.
//
#include <iostream>
#include "dataInput.h"

void dataInput() {
    int value = 0;
    std::cout << "please input:" << std::endl;

    /**
     * cin 拥有数据隐式转换
     * 例如 非0的数 -> true
     */
    std::cin >> value;

    std::cout << "input data" << value << std::endl;
}